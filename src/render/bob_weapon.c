#include "cub3d.h"

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
	y_offset = amplitude * sin((dt->runtime_stats.last_time - dt->runtime_stats.start_time) * speed); // total_time in seconds, or use a step counter;
	return (y_offset);
}