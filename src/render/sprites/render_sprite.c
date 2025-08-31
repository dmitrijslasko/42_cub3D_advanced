#include "cub3d.h"

int render_sprite(t_data *dt, t_sprite *sprite, t_coor *offset, t_coor *sprite_size)
{
	t_coor  coor;
	t_coor  sprite_texture_coor;
	int		targets_sprite;

	targets_sprite = 0;

	// skip if sprite is not shown
	if (sprite->is_shown == 0)
		return (0);

	sprite->is_moving = 1;
	if (dt->time.last_time - sprite->last_frame_time > (1000 / FPS) * 15)
	{
		if (sprite->is_moving)
		{
			sprite->current_frame++;
			if (sprite->current_frame > 4)
				sprite->current_frame = 1;
		}
		else
			sprite->current_frame = 0;
		sprite->last_frame_time = dt->time.last_time;
	}

	coor.y = ft_max(offset->y, 0);
	while (coor.y < sprite_size->y + offset->y && coor.y < WINDOW_H)
	{
		coor.x = ft_max(offset->x, 0);
		while (coor.x < sprite_size->x + offset->x && coor.x < WINDOW_W)
		{
			if (sprite_is_closer_than_wall(dt, &coor, sprite))
			{
				sprite->size = *sprite_size;
				sprite_texture_coor = calculate_tex_x_y(sprite->texture, &coor, offset, sprite);

				sprite_put_color(dt, sprite, &coor, &sprite_texture_coor);
				
				if (coor.x == WINDOW_W / 2)
					targets_sprite = 1; 
			}
			coor.x++;
		}
		coor.y++;
	}

	if (targets_sprite)
		dt->targeted_sprite = sprite;
	else
		dt->targeted_sprite = NULL;
		
	return (EXIT_SUCCESS);
}
