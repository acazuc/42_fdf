/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:51:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 08:03:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "world.h"
#include "mlx.h"

static void		draw_stats_reset(t_world *world)
{
	int		x;
	int		y;

	x = 10;
	while (x < 200)
	{
		y = 10;
		while (y < 210)
		{
			mlx_pixel_put(world->window->mlx, world->window->mlx_window
					, x, y, 0);
			y++;
		}
		x++;
	}
}

void			draw_stats_positions(t_world *world, unsigned int color)
{
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 10, 10, color, "Position");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 20, 30, color, "X: ");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 40, 30, color, ft_itoa(world->position->x));
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 20, 50, color, "Y: ");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 40, 50, color, ft_itoa(world->position->y));
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 20, 70, color, "Z: ");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 40, 70, color, ft_itoa(world->position->z));
}

void			draw_stats_rotations(t_world *world, unsigned int color)
{
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 10, 100, color, "Rotation");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 20, 120, color, "X: ");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 40, 120, color, ft_itoa(world->rotation->x));
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 20, 140, color, "Y: ");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 40, 140, color, ft_itoa(world->rotation->y));
}

void			draw_stats(t_world *world)
{
	unsigned int		color;

	color = 0x0066FF;
	draw_stats_reset(world);
	draw_stats_positions(world, color);
	draw_stats_rotations(world, color);
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 10, 170, color, "Lines: ");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 70, 170, color, ft_itoa(world->lines));
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 10, 190, color, "Points: ");
	mlx_string_put(world->window->mlx, world->window->mlx_window
			, 85, 190, color, ft_itoa(world->points));
}
