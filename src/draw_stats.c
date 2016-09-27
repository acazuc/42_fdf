/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:51:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/20 13:19:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_string(t_world *world, int x, int y, char *string)
{
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, x + 2, y + 2, 0x000000, string);
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, x, y, 0xFFFFFF, string);
}

void			draw_stats_positions(t_world *world)
{
	draw_string(world, 10, 10, "Position");
	draw_string(world, 20, 30, "X: ");
	draw_string(world, 40, 30, ft_itoa(world->position->x));
	draw_string(world, 20, 50, "Y: ");
	draw_string(world, 40, 50, ft_itoa(world->position->y));
	draw_string(world, 20, 70, "Z: ");
	draw_string(world, 40, 70, ft_itoa(world->position->z));
}

void			draw_stats_rotations(t_world *world)
{
	draw_string(world, 10, 100, "Rotation");
	draw_string(world, 20, 120, "X: ");
	draw_string(world, 40, 120, ft_itoa(world->rotation->x));
	draw_string(world, 20, 140, "Y: ");
	draw_string(world, 40, 140, ft_itoa(world->rotation->y));
}

void			draw_stats(t_world *world)
{
	draw_stats_positions(world);
	draw_stats_rotations(world);
	draw_string(world, 10, 170, "Lines: ");
	draw_string(world, 70, 170, ft_itoa(world->lines));
	draw_string(world, 10, 190, "Points: ");
	draw_string(world, 85, 190, ft_itoa(world->points));
}
