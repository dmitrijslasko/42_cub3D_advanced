#include "cub3d.h"

static int	render_floor_and_ceiling(t_data *dt)
{
	draw_sky(dt);
	
	// draw_ceiling(dt);
	draw_floor(dt);
	
	// draw_textured_ceiling(dt);
	draw_textured_floor(dt);

	return (EXIT_SUCCESS);
}

void	render_3d_scene(t_data *dt)
{
	int	i;

	i = 0;
	render_floor_and_ceiling(dt);

	while (i < CASTED_RAYS_COUNT)
	{
		dt->rays[i].id = i;
		render_3d_each_ray(dt, &dt->rays[i], WINDOW_W / CASTED_RAYS_COUNT);
		i++;
	}

	// flashlight
	// draw_flashlight(dt, dt->raycasting_scene_img, 150, 0XAAFFFFFF);
}
