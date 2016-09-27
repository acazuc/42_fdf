/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:44:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 11:45:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		world_init_vectors(t_world *world)
{
	world->position->x = 0;
	world->position->y = 0;
	world->position->x = 0;
	world->rotation->x = 90;
	world->rotation->y = 0;
	world->rotation->z = 0;
}

void			world_init_positions(t_world *world)
{
	world->position->x = world->map->width / 2;
	world->position->y = world->map->width;
	world->position->z = world->map->height;
}

static void		init_keys(t_world *world)
{
	world->rotate_up = 0;
	world->rotate_down = 0;
	world->rotate_left = 0;
	world->rotate_right = 0;
	world->move_up = 0;
	world->move_down = 0;
	world->move_forward = 0;
	world->move_backward = 0;
	world->move_left = 0;
	world->move_right = 0;
}

void			world_init(t_world *world)
{
	if (!(world->rotation = malloc(sizeof(*(world->rotation)))))
		error_quit("Failed to malloc world rotation struct");
	if (!(world->position = malloc(sizeof(*(world->position)))))
		error_quit("Failed to malloc world position struct");
	if (!(world->window = malloc(sizeof(*(world->window)))))
		error_quit("Failed to malloc world window struct");
	world_init_vectors(world);
	world->window->mlx = NULL;
	world->window->mlx_window = NULL;
	world->map = NULL;
	world->window->width = 1920;
	world->window->height = 1080;
	init_keys(world);
}
