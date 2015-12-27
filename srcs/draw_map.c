/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 07:17:02 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 17:06:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "error_quit.h"
#include "draw_line.h"
#include "point.h"
#include "world.h"
#include "map.h"

static void		draw_map_part_ortho(t_world *world, t_point *p1, t_point *p2)
{
	if (p1->x < world->map->width - 1)
	{
		p2->x = p1->x + 1;
		p2->y = world->map->data[(int)p1->z][(int)p1->x + 1];
		p2->z = p1->z;
		draw_line(world, p1, p2);
	}
	if (p1->z < world->map->height - 1)
	{
		p2->x = p1->x;
		p2->y = world->map->data[(int)p1->z + 1][(int)p1->x];
		p2->z = p1->z + 1;
		draw_line(world, p1, p2);
	}
}

static void		draw_map_part_diago(t_world *world, t_point *p1, t_point *p2)
{
	if (p1->z < world->map->height - 1 && p1->x < world->map->width - 1)
	{
		p2->x = p1->x + 1;
		p2->y = world->map->data[(int)p1->z + 1][(int)p1->x + 1];
		p2->z = p1->z + 1;
		draw_line(world, p1, p2);
	}
	if (p1->z > 0 && p1->x < world->map->width - 1)
	{
		p2->x = p1->x + 1;
		p2->y = world->map->data[(int)p1->z - 1][(int)p1->x + 1];
		p2->z = p1->z - 1;
		draw_line(world, p1, p2);
	}
}

static void		draw_map_part(t_world *world, t_point *p1, t_point *p2)
{
	int			x;
	int			z;

	z = -1;
	while (++z < world->map->height)
	{
		x = -1;
		while (++x < world->map->width)
		{
			p1->x = x;
			p1->y = world->map->data[z][x];
			p1->z = z;
			draw_map_part_ortho(world, p1, p2);
			draw_map_part_diago(world, p1, p2);
		}
	}
}

void			draw_map(t_world *world)
{
	t_point		*p1;
	t_point		*p2;

	if (!(p1 = malloc(sizeof(t_point))))
		error_quit("Failed to malloc point number 1");
	if (!(p2 = malloc(sizeof(t_point))))
		error_quit("failed to malloc point number 2");
	world->lines = 0;
	world->points = 0;
	draw_map_part(world, p1, p2);
	free(p1);
	free(p2);
	mlx_put_image_to_window(world->window->mlx, world->window->mlx_window
			, world->window->img, 0, 0);
}
