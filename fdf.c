/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:58:23 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 06:37:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "event_listener.h"
#include "minilibx/mlx.h"
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
		error_quit(NULL, "Invalid parameters.\nUsage:\n./fdf <map_file>");
	if (!(world = malloc(sizeof(*world))))
		error_quit(NULL, "Failed to malloc world struct (fdf.c:32)");
	world_init(world);
	if (!(world->window->mlx = mlx_init()))
		error_quit(world, "Failed to initializing mlx context (fdf.c:35)");
	if (!(world->window->mlx_window = mlx_new_window(world->window->mlx
					, world->window->width
					, world->window->height, "acazuc's fdf")))
		error_quit(world, "Failed to initializing mlx window (fdf.c:39)");
	load_map(world, argv[1]);
	world_init_positions(world);
	mlx_key_hook(world->window->mlx_window, &key_listener, world);
	mlx_mouse_hook(world->window->mlx_window, &mouse_listener, world);
	mlx_expose_hook(world->window->mlx_window, &expose_listener, world);
	mlx_loop(world->window->mlx);
	return (0);
}
