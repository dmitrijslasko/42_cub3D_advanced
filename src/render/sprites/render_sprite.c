#include "cub3d.h"

static int set_animation_speed(t_sprite *sprite, int *sprite_animation_speed)
{
	if (sprite->state == MOVING)
		*sprite_animation_speed = 15;
	else if (sprite->state == HURT)
		*sprite_animation_speed = 10;
	else if (sprite->state == DYING)
		*sprite_animation_speed = 10;
	else if (sprite->state == SHOOTING)
		*sprite_animation_speed = 5;
	else
		*sprite_animation_speed = 15;

	return (EXIT_SUCCESS);
}

int render_sprite(t_data *dt, t_sprite *sprite, t_coor *offset, t_coor *sprite_size)
{
	t_coor  coor;
	t_coor  sprite_texture_coor;
	int		targets_sprite;
	int 	sprite_animation_speed;

	targets_sprite = 0;

	// skip if sprite is not shown
	if (sprite->is_hidden)
		return (EXIT_SUCCESS);

	set_animation_speed(sprite, &sprite_animation_speed);
	
	int frame_time = (1000 / FPS) * sprite_animation_speed;
	
	if (dt->time.last_time - sprite->last_frame_time > frame_time)
	{
		if (sprite->state == MOVING)
		{	
			sprite->current_frame++;
			if (sprite->current_frame > 4)
				sprite->current_frame = 1;
		}
		else if (sprite->state == SHOOTING)
		{
			sprite->current_frame++;
			if (sprite->current_frame > 2)
				sprite->current_frame = 1;
		}
		else if (sprite->state == DYING)
		{
			if (sprite->current_frame < 5)
			{
				if (sprite->current_frame == 0)
					play_sound(DEATH_SOUND);
				sprite->current_frame++;
			}
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
				
				int row = 0;
				int col = 0;

				if (sprite->state == MOVING)
				{
					row = sprite->current_frame;

					float angle = 180.0f - sprite->orientation_to_player;
					col = (int)lroundf(angle / 45.0f);
				}
				if (sprite->state == SHOOTING)
				{
					row = 6;
					col = sprite->current_frame;
				}
				if (sprite->state == HURT || sprite->state == DYING)
				{
					row = 5;
					col = sprite->current_frame;
				}
				if (sprite->state == IDLE)
				{
					float angle = 180.0f - sprite->orientation_to_player;
					col = (int)lroundf(angle / 45.0f);		
				}
				
				sprite_texture_coor = calculate_tex_x_y(sprite->texture, &coor, offset, sprite, row, col);
				sprite_put_color(dt, sprite, &coor, &sprite_texture_coor);
				
				if (sprite->start_x == -1)
				{
					sprite->start_x = coor.x;
					sprite->center_x = coor.x + sprite_size->x / 2;
				}

				float aim;
				float distance;
					
				distance = sprite->distance_to_player;
				aim = ft_max(10, 100 - distance * 20);
				sprite->aim = aim;
				if (distance > dt->player.selected_weapon->max_distance)
					;
				else if (sprite->center_x >= WINDOW_W / 2 - aim && sprite->center_x <= WINDOW_W / 2 + aim && sprite->state != DYING)
					targets_sprite = 1;
			}
			coor.x++;
		}
		coor.y++;
	}

	if (targets_sprite && (sprite->type == ENEMY || sprite->type == PICKUP))
		dt->targeted_sprite = sprite;
		
	return (EXIT_SUCCESS);
}
