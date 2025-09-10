#include "cub3d.h"

int process_sprite_pickups(t_data *dt)
{
	t_sprite *sprite;
	
	sprite = find_sprite_at(dt, (size_t)dt->player.pos.x, (size_t)dt->player.pos.y);

	// health pickup
	if (sprite && !sprite->is_hidden && sprite->map_char == '+')
	{
		sprite->is_hidden = 1;
		system(HEALTH_PICKUP_SYSTEM_CALL);
		dt->player.health_level = ft_min(100, dt->player.health_level += 10);
	}

	// food pickup
	if (sprite && !sprite->is_hidden && ft_strchr(CONSUMABLE_TYPES, sprite->map_char))
	{
		flash_color(dt, WHITE);
		sprite->is_hidden = 1;
		system(EATING_SOUND_SYSTEM_CALL);
		dt->levels[dt->active_level].consumables_collected++;
		
		// level score && total game score
		if (sprite->map_char == dt->levels[dt->active_level].prev_consumable)
			dt->levels[dt->active_level].score_combo += 0.2f;
		else
			dt->levels[dt->active_level].score_combo = 1.0f;
			
		dt->levels[dt->active_level].level_score += 100 * dt->levels[dt->active_level].score_combo;
		dt->gamescore += 100 * dt->levels[dt->active_level].score_combo;

		dt->levels[dt->active_level].prev_consumable = sprite->map_char;
	}

	// key pickup pickup - game won!
	if (sprite && !sprite->is_hidden && ft_strchr(EXIT_TYPES, sprite->map_char))
	{	
		play_sound(LEVEL_CLEARED_SYSTEM_CALL);
		printf("Level #%d finished!\n", dt->active_level);
		print_separator(1, DEF_SEPARATOR_CHAR);
		dt->game_status = LEVEL_FINISH;
	}
	return (EXIT_SUCCESS);
}
