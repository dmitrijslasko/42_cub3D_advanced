#include "cub3d.h"

static int restore_sprites(t_data *dt)
{
	size_t i;

	i = 0;
	while (i < dt->levels[dt->active_level].sprite_count)
	{
		dt->levels[dt->active_level].sprites[i].is_hidden = 0;
		dt->levels[dt->active_level].sprites[i].state = IDLE;
		i++;
	}
	return (EXIT_SUCCESS);
}



int process_game_status(t_data *dt)
{

	dt->player.plane_x = dt->player.orientation_vector.y * (FIELD_OF_VIEW_SCALE);
	dt->player.plane_y = dt->player.orientation_vector.x * (FIELD_OF_VIEW_SCALE);

	// game menu
	// printf("Current game status == %d\n", dt->game_status);
	if (dt->game_status == WELCOME_SCREEN)
	{
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_menu_img->mlx_img, 0, 0);
		if (dt->keys[XK_space] == 0)	
			return (dt->game_status);
		else 
			dt->game_status = MENU_SCREEN;
		dt->keys[XK_space] = 0;
	}

	if (dt->game_status == MENU_SCREEN)
	{
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_menu_img2->mlx_img, 0, 0);
		if (dt->keys[XK_space] == 0)	
			return (dt->game_status);
		else 
			dt->game_status = GAME_SCREEN;
	}

	if (dt->game_status == LEVEL_FINISH)
	{
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_level_cleared_img->mlx_img, 0, 0);
		if (dt->keys[XK_space] == 0)	
			return (dt->game_status);
		else 
		{
			dt->active_level++;
			dt->active_level %= NUMBER_OF_LEVELS;
			update_current_level_pointers(dt);

			dt->levels[dt->active_level].level_score = 0;
			dt->levels[dt->active_level].consumables_collected = 0;
			
			restore_sprites(dt);

			get_init_player_position(dt->map, &dt->player);
			dt->game_status = GAME_SCREEN;
		}
	}

	if (dt->game_status == GAME_WON_SCREEN)
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_won_img->mlx_img, 0, 0);

	return (dt->game_status);
}