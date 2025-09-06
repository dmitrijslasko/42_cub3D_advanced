/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:10:31 by dmlasko           #+#    #+#             */
/*   Updated: 2025/07/24 20:00:27 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_filepath(size_t i, size_t frame)
{
	return (g_sprites[i].filepath[frame]);
}

static int	set_sprite_img(t_data *dt, t_sprite_texture *texture,
	size_t i, size_t frame)
{
	char	*filepath;

	filepath = get_filepath(i, frame);
	printf("%s\n", filepath);
	texture[i].sprite_img[frame] = mlx_xpm_file_to_image(\
		dt->mlx_ptr, \
		filepath, \
		&texture[i].width, \
		&texture[i].height);
	
	return (EXIT_SUCCESS);
}

// int	count_sprite_textures(t_data *dt)
// {
// 	size_t	len;

// 	len = 0;
// 	while (g_sprites[len].map_char)
// 		len++;
// 	dt->sprite_texture_count = len;
	
// 	return (EXIT_SUCCESS);
// }

int	load_sprite_images(t_data *dt, int level_index)
{
	size_t				i;
	t_sprite_texture	*sprite_textures;
	size_t				frame;

	dt->levels[level_index].sprite_textures = malloc(sizeof(t_sprite_texture) * NUMBER_TEXTURES);
	
	sprite_textures = dt->levels[level_index].sprite_textures;
	printf("Number of sprite types to be loaded: %zu\n", dt->levels[level_index].sprite_texture_count);
	
	i = 0;
	while (i < dt->levels[level_index].sprite_texture_count)
	{
		print_separator(1, "-");
		printf("Loading sprite texture for map_char %c\n", g_sprites[i].map_char);
		
		sprite_textures[i].map_char = g_sprites[i].map_char;
		sprite_textures[i].orientation = g_sprites[i].orientation;
		sprite_textures[i].is_sprite_sheet = g_sprites[i].is_sprite_sheet;
		
		frame = 0;
		while (frame < SPRITE_FRAMES)
		{
			set_sprite_img(dt, sprite_textures, i, frame);
			
			sprite_textures[i].sprite_data[frame] = (int *) mlx_get_data_addr(\
							sprite_textures[i].sprite_img[frame], \
							&sprite_textures[i].bpp, \
							&sprite_textures[i].size_line, \
							&sprite_textures[i].endian);
			frame++;
		}
		printf("Sprite image for [%c] loaded!\n", sprite_textures[i].map_char);
		i++;
	}
	print_separator(5, "*");
	return (EXIT_SUCCESS);
}

int	load_sprites(t_data *dt, t_level *level, t_map *map, int i)
{
	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING SPRITES\n" TXT_RESET);
	
	load_sprite_textures(dt, i);

	find_all_sprites(dt, map, i);

	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
