/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:58:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 09:02:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_min_max(t_world *world)
{
	int		x;
	int		y;

	world->min = 127;
	world->max = -128;
	y = 0;
	while (y < world->map->height)
	{
		x = 0;
		while (x < world->map->width)
		{
			if (world->map->data[y][x] < world->min)
				world->min = world->map->data[y][x];
			if (world->map->data[y][x] > world->max)
				world->max = world->map->data[y][x];
			x++;
		}
		y++;
	}
}
