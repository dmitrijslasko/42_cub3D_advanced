/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time_in_ms.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:34:19 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:34:20 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	my_sleep(void)
{
	int				sleep_time;
	struct timespec	ts;

	sleep_time = 1e9 / FPS;
	ts = (struct timespec){0, sleep_time};
	nanosleep(&ts, NULL);
	return (0);
}
