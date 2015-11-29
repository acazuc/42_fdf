/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 20:17:20 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 20:41:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minilibx/mlx.h"
#include "world.h"

static void	world_free_map(t_world *world)
{
	int	z;

	if (world->map->data)
	{
		z = -1;
		while (++z < world->map->height)
			if (world->map->data[z])
				free(world->map->data[z]);
		free(world->map->data);
	}
	free(world->map);
}

void		world_free(t_world *world)
{
	if (world)
	{
		if (world->position)
			free(world->position);
		if (world->rotation)
			free(world->rotation);
		if (world->window)
		{
			if (world->window->mlx && world->window->mlx_window)
				mlx_destroy_window(world->window->mlx
						, world->window->mlx_window);
			free(world->window);
		}
		if (world->map)
			world_free_map(world);
	}
}
