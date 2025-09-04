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
	
	dt->raycasting_scene_img = protected_malloc(sizeof(t_img), dt);
	dt->final_frame_img = protected_malloc(sizeof(t_img), dt);
	dt->minimap_img = protected_malloc(sizeof(t_img), dt);
	dt->ui_img = protected_malloc(sizeof(t_img), dt);
	dt->view = protected_malloc(sizeof(t_view), dt);
	setup_img(dt, dt->final_frame_img, WINDOW_W, WINDOW_H);
	setup_img(dt, dt->raycasting_scene_img, WINDOW_W, WINDOW_H);
	setup_img(dt, dt->minimap_img, MINIMAP_SIZE, MINIMAP_SIZE);
	setup_img(dt, dt->ui_img, WINDOW_W, WINDOW_H);

	// player
	setup_player(dt);
	
	dt->sky_image = protected_malloc(sizeof(t_img), dt);
	load_image(dt, dt->sky_image, SKY_TXT_PATHFILE);

	// game menu image setup
	dt->game_menu_img = protected_malloc(sizeof(t_img), dt);
	dt->game_menu_img2 = protected_malloc(sizeof(t_img), dt);
	dt->game_won_img = protected_malloc(sizeof(t_img), dt);

	load_image(dt, dt->game_menu_img, MENU_PATHFILE);
	load_image(dt, dt->game_menu_img2, MENU2_PATHFILE);
	load_image(dt, dt->game_won_img, GAME_WON_PATHFILE);
	
	load_ui_messages(dt);
	
	dt->targeted_sprite = NULL;
	
	// view
	setup_view(dt);
	
	// weapon aka active item
	load_weapons(dt);
	dt->player.selected_weapon = &dt->weapon[0];
	dt->weapon_current_frame = 0;
	dt->weapon_last_frame_time = 0;

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
	while (i < 3)
	{
		printf(">>>>>>>> %d <<<<<<<<\n", i);
		dt->levels[i].id = i;

		// wall textures
		load_textures(dt, &dt->levels[i]);

		// doors
		init_doors(dt, &dt->levels[i], &dt->levels[i].map);
		// mark_all_cells_that_neighbour_doors(dt);
		
		// sprites - map level
		load_sprites(dt, &dt->levels[i], &dt->levels[i].map, i);

		printf("MAP CHAR 0: %c\n", dt->levels[0].sprites[0].map_char);
		printf("MAP CHAR 1: %c\n", dt->levels[0].sprites[1].map_char);
		printf("MAP CHAR 2: %c\n", dt->levels[0].sprites[2].map_char);
		printf("MAP CHAR 3: %c\n", dt->levels[0].sprites[3].map_char);
		
		int sprite_count = dt->levels[0].sprite_count;
		int texture_count = dt->levels[0].sprite_texture_count;

		set_sprite_textures(dt, i);

		dt->levels[i].level_score = 0;
		dt->levels[i].score_combo = 1.0f;
		dt->levels[i].prev_consumable = 0;
		dt->levels[i].ambient_light = i * 1000.0f;
		i++;
	}
	
	dt->ambient_light = &dt->levels[dt->active_level].ambient_light;
	printf("Level ambient light set!\n");

	// if (BONUS)
	// 	dt->background_music = init_audio();

	return (EXIT_SUCCESS);
}