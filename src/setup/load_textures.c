/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:23 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/24 19:52:27 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_data *dt, t_texture *texture, char *file)
{
	char	*texture_file;

	if (file != NULL)
		texture_file = file;
	else
		texture_file = texture->xpm_file;

	texture->texture_img = mlx_xpm_file_to_image(dt->mlx_ptr,
			texture_file,
			&texture->width,
			&texture->height);
	if (!texture->texture_img)
	{
		//fprintf(stderr, "Failed to load texture from file: %s\n", texture_file);
		return (EXIT_FAILURE);
	}
	texture->texture_data = (int *)mlx_get_data_addr(texture->texture_img,
			&texture->bpp,
			&texture->size_line,
			&texture->endian);
	return (EXIT_SUCCESS);
}

int	load_textures(t_data *dt)
{
	t_texture	*texture;
	size_t		i;
	char	*text_type_repr;

	print_separator_default();
	printf(TXT_YELLOW ">>> LOADING TEXTURES\n" TXT_RESET);
	i = 0;
	//int index;
	while (i < NUMBER_TEXTURES)
	{
		texture = &dt->map.textures[i].texture;
		if (!load_texture(dt, texture, texture->xpm_file))
			printf(TXT_GREEN"Texture [%2zu %4s]: %s loaded!\n"TXT_RESET, i, texture->mapfile_repr, texture->xpm_file);
		else
			printf(TXT_RED"Texture [%2zu]: not provided in the mapfile.\n"TXT_RESET, i);
		i++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
