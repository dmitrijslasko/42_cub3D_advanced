/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:23 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/11 14:19:57 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_data *dt, t_texture *texture, char *file)
{
	char	*texture_file;

	if (file != NULL)
		texture_file = file;
	else
		texture_file = texture->file;
	texture->texture_img = mlx_xpm_file_to_image(dt->mlx_ptr,
			texture_file,
			&texture->width,
			&texture->height);
	if (!texture->texture_img)
	{
		fprintf(stderr, "Failed to load texture from file: %s\n", texture_file);
		return (EXIT_FAILURE);
	}
	texture->texture_data = (int *)mlx_get_data_addr(texture->texture_img,
			&texture->bpp,
			&texture->size_line,
			&texture->endian);
	// printf(TXT_GREEN ">>> Texture loaded! %s\n" TXT_RESET, texture_file);
	return (EXIT_SUCCESS);
}

int	load_textures(t_data *dt)
{
	t_texture	*texture;
	size_t		i;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING TEXTURES\n" TXT_RESET);
	if (PUT_DOOR)
	{
		texture = &dt->map.door.texture;
		if (!load_texture(dt, texture, DOOR_TEXTURE_PATHFILE))
			printf("Door texture loaded!\n");
	}
	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (dt->map.wall_tile[i].is_color)
		{
			printf("Texture [%zu] is color...\n", i);
			i++;
			continue ;
		}
		texture = &dt->map.wall_tile[i].texture;
		if (!load_texture(dt, texture, NULL))
			printf("Texture [%zu]: %s loaded!\n", i, texture->file);
		i++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
