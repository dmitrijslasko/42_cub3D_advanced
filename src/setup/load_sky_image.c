/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sky_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:10:12 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:39:47 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_menu_image(t_data *dt)
{
	int	w;
	int	h;

	print_separator_default();

	printf(TXT_YELLOW ">>> LOADING MENU IMAGE\n" TXT_RESET);

	dt->game_menu_img = protected_malloc(sizeof(t_img), dt);
	dt->game_menu_img->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr, MENU_PATHFILE, &w, &h);
	if (!dt->game_menu_img->mlx_img)
	{
		fprintf(stderr, "Failed to load menu image\n");
		return (EXIT_FAILURE);
	}
	dt->game_menu_img->width = w;
	dt->game_menu_img->height = h;
	dt->game_menu_img->addr = mlx_get_data_addr(dt->game_menu_img->mlx_img,
			&dt->game_menu_img->bpp, &dt->game_menu_img->line_len,
			&dt->game_menu_img->endian);
	
	printf("Loaded menu image: %d x %d px\n", w, h);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	
	return (EXIT_SUCCESS);
}

int	load_menu_image_2(t_data *dt)
{
	int	w;
	int	h;

	print_separator_default();

	printf(TXT_YELLOW ">>> LOADING MENU IMAGE\n" TXT_RESET);

	dt->game_menu_img2 = protected_malloc(sizeof(t_img), dt);
	dt->game_menu_img2->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr, MENU2_PATHFILE, &w, &h);
	if (!dt->game_menu_img->mlx_img)
	{
		fprintf(stderr, "Failed to load menu image\n");
		return (EXIT_FAILURE);
	}
	dt->game_menu_img2->width = w;
	dt->game_menu_img2->height = h;
	dt->game_menu_img2->addr = mlx_get_data_addr(dt->game_menu_img2->mlx_img,
			&dt->game_menu_img2->bpp, &dt->game_menu_img2->line_len,
			&dt->game_menu_img2->endian);
	
	printf("Loaded menu image: %d x %d px\n", w, h);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	
	return (EXIT_SUCCESS);
}

int	load_menu_image_3(t_data *dt)
{
	int	w;
	int	h;

	print_separator_default();

	printf(TXT_YELLOW ">>> LOADING MENU IMAGE\n" TXT_RESET);

	dt->game_won_img = protected_malloc(sizeof(t_img), dt);
	dt->game_won_img->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr, GAME_WON_PATHFILE, &w, &h);
	if (!dt->game_menu_img->mlx_img)
	{
		fprintf(stderr, "Failed to load menu image\n");
		return (EXIT_FAILURE);
	}
	dt->game_won_img->width = w;
	dt->game_won_img->height = h;
	dt->game_won_img->addr = mlx_get_data_addr(dt->game_won_img->mlx_img,
			&dt->game_won_img->bpp, &dt->game_won_img->line_len,
			&dt->game_won_img->endian);
	
	printf("Loaded menu image: %d x %d px\n", w, h);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	
	return (EXIT_SUCCESS);
}


int	load_sky_image(t_data *dt)
{
	int	w;
	int	h;

	print_separator_default();

	printf(TXT_YELLOW ">>> LOADING SKY IMAGE\n" TXT_RESET);

	dt->sky_image = protected_malloc(sizeof(t_img), dt);
	dt->sky_image->mlx_img = mlx_xpm_file_to_image(dt->mlx_ptr, SKY_TXT_PATHFILE, &w, &h);
	if (!dt->sky_image->mlx_img)
	{
		fprintf(stderr, "Failed to load sky texture\n");
		return (EXIT_FAILURE);
	}
	dt->sky_image->width = w;
	dt->sky_image->height = h;
	dt->sky_image->addr = mlx_get_data_addr(dt->sky_image->mlx_img,
			&dt->sky_image->bpp, &dt->sky_image->line_len,
			&dt->sky_image->endian);
	
	printf("Loaded sky texture: %d x %d px\n", w, h);
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	
	return (EXIT_SUCCESS);
}
