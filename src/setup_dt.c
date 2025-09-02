#include "cub3d.h"

static int setup_player(t_data *dt)
{
	dt->player.ammo_level = STARTING_AMMO_LEVEL;
	dt->player.health_level = STARTING_HEALTH_LEVEL;
	return (EXIT_SUCCESS);
}

int	setup_dt(t_data *dt)
{

	
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
	
	// wall textures
	load_textures(dt);

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
	
	// doors
	init_doors(dt);
	mark_all_cells_that_neighbour_doors(dt);
	
	// sprites
	load_sprites(dt);
	// exit (1);
	dt->targeted_sprite = dt->sprites;
	
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

	// ambient light
	dt->ambient_light = 3000.0f;

	// gamescore
	dt->gamescore = 0;
	dt->consumables_collected = 0;
	dt->score_combo = 1.0f;
	dt->prev_consumable = 0;

	// if (BONUS)
	// 	dt->background_music = init_audio();

	return (EXIT_SUCCESS);
}