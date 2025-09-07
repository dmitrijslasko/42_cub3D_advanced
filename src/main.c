/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:12:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 18:40:59 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sound.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	const char *game_levels[] = {	"./maps/good/01_level.cub",
									"./maps/good/02_level.cub",
									"./maps/good/03_level.cub",
									"./maps/good/04_level.cub",
									NULL}; 
	
	init_dt(&dt);
	check_and_parse_all_maps(&dt, argc, game_levels);

	// precalculate sin and cos lookup tables
	precalculate_trig_tables(&dt);
	
	// setup minilibx stuff
	if (setup_mlx_and_win(&dt))
		return (MLX_ERROR);
		
	// mimic full screen for immersive gameplay
	system("gsettings set org.gnome.desktop.a11y.applications screen-magnifier-enabled false");
	mimic_fullscreen();

	move_mouse_to_center_of_active_window();

	setup_keyboard_and_mouse_controls(&dt);

	// setup dt - sets up the whole game structure and data
	setup_dt(&dt);

	dt.game_status = WELCOME_SCREEN;
	dt.active_level = 3;
	update_current_level_pointers(&dt);
	get_init_player_position(dt.map, &dt.player);
	printf("Game status set!\n");

	draw_minimap_base_img(&dt);

	print_separator(3, DEF_SEPARATOR_CHAR);

	printf("Current level: %d\n", dt.active_level);
	printf("🎮 Starting game!\n");

	printf("Consumables to collect in this level: %d\n", get_curr_level(&dt)->level_consumable_count);
	print_separator(1, DEF_SEPARATOR_CHAR);
	
	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	return (EXIT_SUCCESS);
}
