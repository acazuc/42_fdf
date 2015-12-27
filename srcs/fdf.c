/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:58:23 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 17:07:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "event_listener.h"
#include "window_init.h"
#include "world_init.h"
#include "draw_stats.h"
#include "error_quit.h"
#include "load_map.h"
#include "draw_map.h"
#include "vector.h"
#include "world.h"
#include "map.h"

int		main(int argc, char **argv)
{
	t_world		*world;

	if (argc != 2)
		error_quit("Invalid parameters.\nUsage:\n./fdf <map_file>");
	if (!(world = malloc(sizeof(*world))))
		error_quit("Failed to malloc world struct");
	world_init(world);
	window_init(world);
	load_map(world, argv[1]);
	world_init_positions(world);
	mlx_key_hook(world->window->mlx_window, &key_listener, world);
	mlx_expose_hook(world->window->mlx_window, &expose_listener, world);
	mlx_loop(world->window->mlx);
	return (0);
}
