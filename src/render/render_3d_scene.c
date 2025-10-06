#include "cub3d.h"

static int	render_floor_and_ceiling(t_data *dt)
{
	if (dt->map->textures[SKY].texture.xpm_file_pathfile)
		draw_sky(dt);
	else
		draw_textured_ceiling(dt);
	draw_textured_floor(dt);

	// draw_ceiling(dt);
	// draw_floor(dt);

	return (EXIT_SUCCESS);
}

void	render_3d_scene(t_data *dt)
{
	int	i;

	i = 0;
	draw_background(dt->raycasting_scene_img, BLACK);
	render_floor_and_ceiling(dt);

	while (i < CASTED_RAYS_COUNT)
	{
		dt->rays[i].id = i;
		render_3d_each_ray(dt, &dt->rays[i]);
		i++;
	}

	// flashlight
	if (dt->view->flashlight_on)
		draw_flashlight(dt, dt->raycasting_scene_img, 150, 0XAAFFFFFF);
}
