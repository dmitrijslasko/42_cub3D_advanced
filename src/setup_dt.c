#include "cub3d.h"

static int setup_player(t_data *dt)
{
	print_separator_default();
	printf(TXT_YELLOW ">>> SETTING UP PLAYER\n" TXT_RESET);
	// dt->player.ammo_level = STARTING_AMMO_LEVEL;
	dt->player.health_level = STARTING_HEALTH_LEVEL;
	return (EXIT_SUCCESS);
}

int	setup_dt(t_data *dt)
{
	printf("Setting up data struct!\n");
	init_rays(dt);
	init_keys(dt);
	
	dt->final_frame_img = protected_malloc(sizeof(t_img), dt);
	dt->raycasting_scene_img = protected_malloc(sizeof(t_img), dt);
	dt->minimap_img = protected_malloc(sizeof(t_img), dt);
	dt->ui_img = protected_malloc(sizeof(t_img), dt);

	setup_img(dt, dt->final_frame_img, WINDOW_W, WINDOW_H);
	setup_img(dt, dt->raycasting_scene_img, WINDOW_W, WINDOW_H);
	setup_img(dt, dt->minimap_img, MINIMAP_SIZE, MINIMAP_SIZE);
	setup_img(dt, dt->ui_img, WINDOW_W, WINDOW_H);

	// player
	setup_player(dt);
	
	dt->view = protected_malloc(sizeof(t_view), dt);

	// game menu image setup
	dt->game_menu_img = protected_malloc(sizeof(t_img), dt);
	dt->game_menu_img2 = protected_malloc(sizeof(t_img), dt);
	dt->game_level_cleared_img = protected_malloc(sizeof(t_img), dt);
	dt->game_won_img = protected_malloc(sizeof(t_img), dt);

	load_image(dt, dt->game_menu_img, MENU_PATHFILE);
	load_image(dt, dt->game_menu_img2, MENU2_PATHFILE);
	load_image(dt, dt->game_level_cleared_img, LEVEL_CLEARED_PATHFILE);
	load_image(dt, dt->game_won_img, GAME_WON_PATHFILE);
	
	load_ui_messages(dt);
	
	dt->targeted_sprite = NULL;
	
	// view
	setup_view(dt);
	
	// weapon aka active item
	load_weapons(dt);
	dt->player.selected_weapon = &dt->weapon[WEAPON_KNIFE];
	dt->weapon_current_frame = 0;
	dt->weapon_last_frame_time = 0;
	dt->rounds_fired = 0;

	// time
	dt->time.start_time = get_current_time_in_ms();
	dt->time.last_time = 0;

	// test value for in-game tests
	dt->test_value_1 = 0.0f;
	dt->test_value_2 = 0.0f;
	dt->test_value_3 = 0.0f;
	dt->test_value_4 = 0.0f;

	// gamescore
	dt->gamescore = 0;
	
	int i = 0;
	while (i < NUMBER_OF_LEVELS)
	{
		printf(">>>>>>>> %d <<<<<<<<\n", i);
		dt->levels[i].id = i;

		// wall textures
		dt->levels[i].sky_image = NULL;
		load_textures(dt, &dt->levels[i]);
		if (dt->levels[i].map.textures[SKY].texture.xpm_file_pathfile)
		{
			dt->levels[i].sky_image = protected_malloc(sizeof(t_img), dt);
			load_image(dt, dt->levels[i].sky_image, dt->levels[i].map.textures[SKY].texture.xpm_file_pathfile);
		}

		// doors
		init_doors(dt, &dt->levels[i], &dt->levels[i].map);
		mark_all_cells_that_neighbour_doors(dt, &dt->levels[i], &dt->levels[i].map);
		
		// sprites - map level
		load_sprites(dt, &dt->levels[i], &dt->levels[i].map, i);
		set_sprite_textures(dt, i);

		dt->levels[i].level_score = 0;
		dt->levels[i].score_combo = 1.0f;
		dt->levels[i].prev_consumable = 0;
		dt->levels[i].ambient_light = 10.0f;
		i++;
	}
	// if (BONUS)
	// dt->background_music = init_audio();

	return (EXIT_SUCCESS);
}