/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:09:21 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/24 18:59:38 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_prompt_message(t_data *dt)
{
	t_coor	cell_ahead;

	cell_ahead = get_cell_ahead(dt);
	dt->player.cell_type_ahead = get_cell_type(&dt->map, &cell_ahead);
	if (ft_strchr(DOOR_TYPES, dt->player.cell_type_ahead))
		dt->view->show_door_open_message = 1;
	else
		dt->view->show_door_open_message = 0;
	return (EXIT_SUCCESS);
}

static int	render_minimap_and_ui(t_data *dt)
{
	if (dt->view->show_minimap)
		put_img_to_img(dt->final_frame_img, dt->minimap_img, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);
	render_ui(dt);
	return (EXIT_SUCCESS);
}

void	bob_walls(t_data *dt)
{
		float speed;
		float amplitude;
		int y_offset;
		if (dt->player.is_moving == 1)
		{
			amplitude = 2.0f;
			speed = 0.008f;
			y_offset = amplitude * sin((dt->time.last_time - dt->time.start_time) * speed); // total_time in seconds, or use a step counter
			dt->view->screen_center_y += y_offset;
		}

}

int	bob_weapon(t_data *dt)
{
	float speed;
	int amplitude;
	int y_offset;

	speed = 0.004f; // higher = faster oscillation (tweak to taste)
	if (dt->player.move_speed_multiplier == 1)
		amplitude = 10;
	else
		amplitude = 2;
	y_offset = amplitude * sin((dt->time.last_time - dt->time.start_time) * speed); // total_time in seconds, or use a step counter;
	return (y_offset);
}

int print_out_sprite_info(t_data *dt)
{
	t_sprite 	*sprites;
	size_t		i;
	float		distance;

	sprites = dt->sprites;
	i = 0;
	while (i < dt->sprite_count)
	{
		distance = sprites[i].distance_to_player;
		//printf("[%zu] Distance: %.2f\n", i, distance);
		i++;
	}
}

int process_sprite_pickups(t_data *dt)
{
	t_sprite *sprite = find_sprite_at(dt, (size_t)dt->player.pos.x, (size_t)dt->player.pos.y);

	// health pickup
	if (sprite && !sprite->is_hidden && sprite->map_char == '+')
	{
		sprite->is_hidden = 1;
		system("aplay sounds/health.wav &");
		dt->player.health_level = ft_min(100, dt->player.health_level += 10);
	}

	// food pickup
	if (sprite && !sprite->is_hidden && ft_strchr(CONSUMABLE_TYPES, sprite->map_char))
	{
		sprite->is_hidden = 1;
		dt->consumables_collected++;
		dt->gamescore += 100 * dt->score_combo;
		if (!dt->prev_consumable || sprite->map_char == dt->prev_consumable)
			dt->score_combo += 0.2f;
		else
			dt->score_combo = 1.0f;
		dt->prev_consumable = sprite->map_char;
	}

	// key pickup pickup - game won!
	if (sprite && !sprite->is_hidden && sprite->map_char == '$')
	{
		if (dt->level_consumable_count > dt->consumables_collected)
			mlx_string_put(dt->mlx_ptr, dt->win_ptr, 240, 300, WHITE, "Not all goodies are collected!");
		else 
		{
			printf("Game won!\n");
			print_separator(3, DEF_SEPARATOR_CHAR);
			dt->game_status = GAME_WON_SCREEN;
			// keypress_exit(dt);
		}
	}
	return (EXIT_SUCCESS);
}

int animate_weapon(t_data *dt)
{
	long now;

	if (dt->weapon_is_animating == 1)
	{
		now = dt->time.last_time;

		if (now - dt->weapon_last_frame_time > (1000 / FPS) * 2)
		{
			dt->weapon_current_frame++;
			dt->weapon_last_frame_time = now;
			if (dt->weapon_current_frame == 5)
			{
				dt->weapon_is_animating = 0;
				dt->weapon_current_frame = 0;
			}
		}
	}
	return (EXIT_SUCCESS);
}

int animate_doors(t_data *dt)
{
    int i;
    t_door *door;

    i = 0;
    while (i < dt->door_count)
    {
        door = &dt->doors[i];

        // Opening
        if (door->is_opening)
        {
            door->open_progress += door->speed;
            if (door->open_progress >= 1.0f)
            {
                door->open_progress = 1.0f;
                door->is_opening = 0;
                door->opening_finish_time = dt->time.last_time;
            }
        }
        // Closing after 2 seconds
        else if (dt->time.last_time - door->opening_finish_time > DOOR_AUTOCLOSURE_TIME_MS)
        {
			// printf("door @ %d %d vs ", door->cell_x, door->cell_y);
			// printf("player @ %f %f\n", dt->player.pos.x, dt->player.pos.y);
			if (door->cell_x == (int) dt->player.pos.x && door->cell_y == (int) dt->player.pos.y)
			{
				// puts("Door blocked by the player!");
				i++;
				continue ;
			}
            if (door->open_progress > 0.0f)
            {
                door->open_progress -= door->speed;
                if (door->open_progress < 0.0f)
                    door->open_progress = 0.0f;
            }
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

int process_game_status(t_data *dt)
{
	// game menu
	if (dt->game_status == WELCOME_SCREEN)
	{
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_menu_img->mlx_img, 0, 0);
		if (dt->keys[XK_space] == 0)	
			return (EXIT_SUCCESS);
		else 
			dt->game_status = MENU_SCREEN;
			dt->keys[XK_space] = 0;
	}

	if (dt->game_status == MENU_SCREEN)
	{
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_menu_img2->mlx_img, 0, 0);
		if (dt->keys[XK_space] == 0)	
			return (EXIT_SUCCESS);
		else 
			dt->game_status = GAME_SCREEN;
	}

	if (dt->game_status == GAME_WON_SCREEN)
	{
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_won_img->mlx_img, 0, 0);
		if (dt->keys[XK_space] == 0)	
			return (EXIT_SUCCESS);
		else 
			dt->game_status = GAME_SCREEN;
	}

	return (1);
}

int	render_frame(void *param)
{
	t_data		*dt;
	long		current_time;
	int 		y_offset;

	dt = (t_data *) param;

	// reset_mouse_position(dt);

	current_time = get_current_time_in_ms();
	dt->time.delta_time = current_time - dt->time.last_time;
	if (dt->time.delta_time < (1000 / FPS))
	{
		my_sleep();
		return (0);
	}
	dt->time.last_time = current_time;

	if (process_game_status(dt) == 0)
		return (EXIT_SUCCESS);

	process_keyboard_keypresses(dt);	

	// draw game menu
	animate_weapon(dt);
	
	animate_doors(dt);

	calculate_all_rays(dt);

	render_3d_scene(dt);
	
	put_img_to_img(dt->final_frame_img, dt->raycasting_scene_img, 0, 0);

	if (RENDER_SPRITES)
		render_all_sprites(dt);
	
	// show minimap
	if (dt->view->show_minimap)
		update_minimap(dt);

	render_minimap_and_ui(dt);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr,dt->final_frame_img->mlx_img, 0, 0);
	
	// time stats
	// int y = 20;
	// print_time_stats(dt, dt->mlx_ptr, dt->win_ptr, &y);
	
	show_debug_info(dt);
 	show_player_info(dt);
	show_level_info(dt);

	process_sprite_pickups(dt);

	update_prompt_message(dt);
	if (dt->view->show_door_open_message)
	{
		mlx_string_put(dt->mlx_ptr, dt->win_ptr, 240, 300, WHITE, "Press E to open the shoji");
		// render_ui_message(dt);
	}

	y_offset = 0;
	if (ENABLE_BOBBING)
	{
		bob_walls(dt);
		y_offset = bob_weapon(dt);
	}
	// render weapon


	
	if (dt->player.selected_weapon->type == WEAPON_PISTOL)
		put_img_to_img(dt->final_frame_img, &dt->weapon_img[dt->weapon_current_frame], (WINDOW_W - 360) / 2 + y_offset / 4, 20 + y_offset);
	dt->frames_drawn_count++;
	print_out_sprite_info(dt);

	return (EXIT_SUCCESS);
}
