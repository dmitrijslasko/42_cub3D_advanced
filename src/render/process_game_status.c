#include "cub3d.h"

int process_game_status(t_data *dt)
{
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
			get_init_player_position(dt->map, &dt->player);
			dt->game_status = GAME_SCREEN;
		}
	}

	if (dt->game_status == GAME_WON_SCREEN)
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->game_won_img->mlx_img, 0, 0);

	return (dt->game_status);
}