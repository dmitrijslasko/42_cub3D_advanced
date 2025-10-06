/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_distance_shadow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:08:57 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:08:58 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	apply_distance_shadow(float distance, int *color)
{
	float	shade;
	int		r;
	int		g;
	int		b;

	shade = 1.0f / (1.0f + distance * DISTANCE_SHADOW_STRENGTH);
	if (shade < 0.1f)
		shade = 0.1f;
	r = ((*color >> 16) & 0xFF) * shade;
	g = ((*color >> 8) & 0xFF) * shade;
	b = ((*color >> 0) & 0xFF) * shade;
	
	*color = (r << 16) | (g << 8) | (b << 0);
	return (EXIT_SUCCESS);
}

// Extract RGB from 0xAARRGGBB (or 0x00RRGGBB if no alpha)
static inline uint8_t get_r(uint32_t color) { return (color >> 16) & 0xFF; }
static inline uint8_t get_g(uint32_t color) { return (color >> 8) & 0xFF; }
static inline uint8_t get_b(uint32_t color) { return color & 0xFF; }

// Reduce saturation by factor (0.0 = no change, 1.0 = grayscale)
uint32_t reduce_saturation(uint32_t color, float factor)
{
    uint8_t r = get_r(color);
    uint8_t g = get_g(color);
    uint8_t b = get_b(color);

    // Luminance (grayscale intensity)
    uint8_t gray = (uint8_t)(0.3f * r + 0.59f * g + 0.11f * b);

    // Blend with gray
    r = (uint8_t)((1.0f - factor) * r + factor * gray);
    g = (uint8_t)((1.0f - factor) * g + factor * gray);
    b = (uint8_t)((1.0f - factor) * b + factor * gray);

    return (r << 16) | (g << 8) | b;
}

// BUG: Strange behaviour for the return 1 statement
int	apply_shadow(t_ray *ray, int *color, float strength)
{
	float	shade;
	int		r;
	int		g;
	int		b;

	if (ft_strchr(WALL_TYPES, ray->cell_type - '0'))
		return (1);
	shade = 1.0f / (1.0f + strength);
	if (shade < 0.1f)
		shade = 0.1f;
	r = ((*color >> 16) & 0xFF) * shade;
	g = ((*color >> 8) & 0xFF) * shade;
	b = ((*color >> 0) & 0xFF) * shade;
	*color = (r << 16) | (g << 8) | (b << 0);	
	return (EXIT_SUCCESS);
}
