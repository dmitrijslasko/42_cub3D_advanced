/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:10:31 by dmlasko           #+#    #+#             */
/*   Updated: 2025/07/01 21:32:29 by fvargas          ###   ########.fr       */
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
	texture[i].sprite_img[frame] = mlx_xpm_file_to_image(\
		dt->mlx_ptr, \
		filepath, \
		&texture[i].width, \
		&texture[i].height);
	return (EXIT_SUCCESS);
}

int	count_sprite_textures(t_data *dt)
{
	size_t	len;

	len = 0;
	while (g_sprites[len].map_char)
		len++;
	dt->sprite_texture_count = len;
	return (EXIT_SUCCESS);
}

int	load_sprite_images(t_data *dt)
{
	size_t				i;
	t_sprite_texture	*sprite_textures;

	sprite_textures = dt->sprite_textures;
	printf("Sprite types to be loaded: %zu\n", dt->sprite_texture_count);
	i = 0;
	while (i < dt->sprite_texture_count)
	{
		sprite_textures[i].type = g_sprites[i].map_char;
		set_sprite_img(dt, sprite_textures, i, 0);
		sprite_textures[i].sprite_data[0] = (int *)mlx_get_data_addr(\
						sprite_textures[i].sprite_img[0], \
						&sprite_textures[i].bpp, \
						&sprite_textures[i].size_line, \
						&sprite_textures[i].endian);
		set_sprite_img(dt, sprite_textures, i, 1);
		sprite_textures[i].sprite_data[1] = (int *)mlx_get_data_addr(\
						sprite_textures[i].sprite_img[1], \
						&sprite_textures[i].bpp, \
						&sprite_textures[i].size_line, \
						&sprite_textures[i].endian);
		printf("Sprite image for %c loaded!\n", sprite_textures[i].type);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	load_sprites(t_data *dt)
{
	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING SPRITES\n" TXT_RESET);
	load_sprite_textures(dt);
	find_all_sprites(dt);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
