/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:58:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 09:03:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	get_min_max(world);
	mlx_key_hook(world->window->mlx_window, &key_listener, world);
	mlx_expose_hook(world->window->mlx_window, &expose_listener, world);
	mlx_loop(world->window->mlx);
	return (0);
}
