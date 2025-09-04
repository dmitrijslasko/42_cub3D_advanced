#include "cub3d.h"

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