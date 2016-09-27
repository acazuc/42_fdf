/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:58:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 11:47:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		do_move(t_world *world)
{
	if (world->rotate_up)
		rotate_up(world);
	if (world->rotate_down)
		rotate_down(world);
	if (world->rotate_left)
		rotate_left(world);
	if (world->rotate_right)
		rotate_right(world);
	if (world->move_down)
		world->position->y -= 1;
	if (world->move_up)
		world->position->y += 1;
	if (world->move_forward)
		step_forward(world);
	if (world->move_left)
		step_left(world);
	if (world->move_backward)
		step_backward(world);
	if (world->move_right)
		step_right(world);
}

static int		loop_listener(void *data)
{
	t_world		*world;

	world = (t_world*)data;
	draw_reset(world);
	do_move(world);
	draw_map(world);
	draw_stats(world);
	return (0);
}

int				main(int argc, char **argv)
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
	mlx_do_key_autorepeatoff(world->window->mlx);
	mlx_hook(world->window->mlx_window, 2, 1, &key_press_listener, world);
	mlx_hook(world->window->mlx_window, 3, 2, &key_release_listener, world);
	mlx_loop_hook(world->window->mlx, &loop_listener, world);
	//mlx_key_hook(world->window->mlx_window, &key_listener, world);
	//mlx_expose_hook(world->window->mlx_window, &expose_listener, world);
	mlx_loop(world->window->mlx);
	return (0);
}
