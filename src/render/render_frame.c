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

int animate_weapon(t_data *dt)
{
	long 	now;
	t_weapon *weapon;

	weapon = dt->player.selected_weapon;

	debug_print("Animating weapons...");
	if (dt->weapon_is_animating == 1)
	{
		if (dt->targeted_sprite && weapon->total_ammo > 0)
			dt->targeted_sprite->state = DYING;
		now = dt->time.last_time;
		if (now - dt->weapon_last_frame_time > (1000 / FPS) * 2)
		{
			if (dt->weapon_current_frame == 2)
			{
				dt->player.selected_weapon->total_ammo = ft_max(0, weapon->total_ammo - 1);
				dt->rounds_fired++;
			}
			dt->weapon_current_frame++;
			if (dt->weapon_current_frame == 5 || (dt->weapon_current_frame == 1 && weapon->total_ammo == 0))
			{
				dt->weapon_is_animating = 0;
				dt->weapon_current_frame = 0;
				dt->rounds_fired = 0;
			}
			dt->weapon_last_frame_time = now;
		}
	}
	return (EXIT_SUCCESS);
}

int animate_doors(t_data *dt)
{
    int i;
    t_door *door;
	int		door_count;

	debug_print("Animating doors...\n");
    i = 0;
    while (i < dt->door_count)
    {
		door = &dt->doors[i];

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
        else if (dt->time.last_time - door->opening_finish_time > DOOR_AUTOCLOSURE_TIME_MS)
        {
			if (door->cell_x == (int) dt->player.pos.x && door->cell_y == (int) dt->player.pos.y)
			{
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
	// printf("Finished animating doors...\n");
    return (EXIT_SUCCESS);
}

int animate_sprites(t_data *dt)
{
	size_t	i;
	t_x_y	*pos;
	float	*speed;
	float	distance_to_wall;

	i = 0;
	while (i < dt->sprite_count)
	{
		if (!ft_strchr(ENEMY_SPRITES, dt->sprites[i].map_char))
		{
			i++;
			continue ;
		}
		
		speed = &dt->sprites[i].speed;
		pos = &dt->sprites[i].pos;

		if (dt->sprites[i].state == DYING)
		{
			i++;
			continue ;
		}
			
		dt->sprites[i].state = MOVING;

		distance_to_wall = 0.5f * (1 - 2 * (*speed < 0));

		t_x_y test_pos;
		test_pos.x = pos->x;
		test_pos.y = pos->y;

		if (dt->sprites[i].orientation == 0.0f || dt->sprites[i].orientation == 180.0f)
			test_pos.x += *speed + distance_to_wall;
		
		if (dt->sprites[i].orientation == 90.0f || dt->sprites[i].orientation == 270.0f)
			test_pos.y += *speed + distance_to_wall;

		char cell_type = get_cell_by_coordinates_float(dt->map, test_pos.y, test_pos.x)->map_char;

		if (ft_strchr(WALL_TYPES, cell_type))
		{
			dt->sprites[i].orientation += 180.0f;
			if (dt->sprites[i].orientation >= 360.0f)
				dt->sprites[i].orientation -= 360.f;
			*speed *= -1;
		}
		else
		{
			if (dt->sprites[i].orientation == 0.0f || dt->sprites[i].orientation == 180.0f)
				pos->x += *speed;
			if (dt->sprites[i].orientation == 90.0f || dt->sprites[i].orientation == 270.0f)
				pos->y += *speed;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	render_frame(void *param)
{
	t_data		*dt;
	long		current_time;
	int 		y_offset;

	dt = (t_data *) param;

	reset_mouse_position(dt);

	current_time = get_current_time_in_ms();
	dt->time.delta_time = current_time - dt->time.last_time;
	if (dt->time.delta_time < (1000 / FPS))
	{
		my_sleep();
		return (0);
	}
	dt->time.last_time = current_time;

	dt->sprite_pulse_coef += dt->sprite_pulse_step;
	if (dt->sprite_pulse_coef <= -10 || dt->sprite_pulse_coef >= 10)
		dt->sprite_pulse_step *= -1;
	
	if (process_game_status(dt) != GAME_SCREEN)
		return (dt->game_status);

	process_keyboard_keypresses(dt);

	animate_doors(dt);

	calculate_all_rays(dt);

	render_3d_scene(dt);
	
	// for (int i = 0; i < 4; i++)
	// {
	// 	for (int j = 0; j < dt->levels[i].sprite_count; j++)
	// 		printf("%f\n", dt->levels[i].sprites[i].speed);
	// 	print_separator_default();
	// }

	put_img_to_img(dt->final_frame_img, dt->raycasting_scene_img, 0, 0);

	if (RENDER_SPRITES)
	{
		animate_sprites(dt);
		render_all_sprites(dt);
	}
	
	// show minimap
	if (dt->view->show_minimap)
		update_minimap(dt);
	render_minimap_and_ui(dt);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr,dt->final_frame_img->mlx_img, 0, 0);
	
	show_debug_info(dt);
 	show_player_info(dt);
	show_level_info(dt);

	process_sprite_pickups(dt);

	// render_ui_message(dt);
	update_prompt_message(dt);
	if (dt->view->show_door_open_message)
		mlx_string_put(dt->mlx_ptr, dt->win_ptr, 240, 300, WHITE, OPEN_DOOR_PROMPT);
	
	y_offset = 0;
	if (ENABLE_BOBBING)
	{
		bob_walls(dt);
		y_offset = bob_weapon(dt);
	}

	// render weapon	
	if (dt->player.selected_weapon->type != WEAPON_NO_WEAPON)
	{
		animate_weapon(dt);
		put_img_to_img(dt->final_frame_img, &dt->weapon[dt->player.selected_weapon->type].frames[dt->weapon_current_frame], (WINDOW_W - 360) / 2 + y_offset / 4, 20 + y_offset);
		
		if (dt->weapon_current_frame == 3 && dt->rounds_fired < dt->player.selected_weapon->rounds_fired)
			dt->weapon_current_frame--;
	}

	dt->frames_drawn_count++;
	// print_out_sprite_info(dt);

	return (EXIT_SUCCESS);
}
