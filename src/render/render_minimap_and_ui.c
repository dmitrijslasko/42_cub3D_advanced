#include "cub3d.h"

int	render_minimap_and_ui(t_data *dt)
{
	if (dt->view->show_minimap)
		put_img_to_img(dt->final_frame_img, dt->minimap_img, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);
	render_ui(dt);
	return (EXIT_SUCCESS);
}
