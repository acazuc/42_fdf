/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:32:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 09:13:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			new_x(t_world *world, t_point *point)
{
	double	x;

	x = cos(world->rotation->y / 180.0 * 3.14)
		* (point->x - world->position->x)
		- sin(world->rotation->y / 180.0 * 3.14)
		* ((point->z - world->position->z) + world->map->height);
	return (x * 50);
}

double			new_y(t_world *world, t_point *point)
{
	double	y;

	y = sin(world->rotation->x / 180.0 * 3.14)
		* (cos(world->rotation->y / 180.0 * 3.14)
		* ((point->z - world->position->z) + world->map->height)
		+ sin(world->rotation->y / 180.0 * 3.14)
		* (point->x - world->position->x))
		+ cos(world->rotation->x / 180.0 * 3.14)
		* (point->y - world->position->y);
	return (y * 50);
}

double			new_z(t_world *world, t_point *point)
{
	double	z;

	z = cos(world->rotation->x / 180.0 * 3.14)
		* (cos(world->rotation->y / 180.0 * 3.14)
		* ((point->z - world->position->z) + world->map->height)
		+ sin(world->rotation->y / 180.0 * 3.14)
		* (point->x - world->position->x))
		- sin(world->rotation->x / 180.0 * 3.14)
		* (point->y - world->position->y);
	return (z / 50);
}

int				get_screen_x(t_world *world, t_point *point)
{
	double	n_x;
	double	n_z;

	n_x = new_x(world, point);
	n_z = new_z(world, point);
	return (world->window->width / 2 + n_x / n_z);
}

int				get_screen_y(t_world *world, t_point *point)
{
	double	n_y;
	double	n_z;

	n_y = new_y(world, point);
	n_z = new_z(world, point);
	return (world->window->height / 2 + n_y / n_z);
}
