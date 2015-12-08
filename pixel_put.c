/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:16:19 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/08 08:24:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "world.h"

void	pixel_put(t_world *world, int x, int y, unsigned int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	c;

	c = mlx_get_color_value(world->window->mlx, color);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	if (x >= 0 && x <= world->window->width
			&& y >= 0 && y <= world->window->height)
	{
		world->window->data[y * world->window->width * world->window->bpp / 8
			+ world->window->bpp / 8 * x] = b;
		world->window->data[y * world->window->width * world->window->bpp / 8
			+ world->window->bpp / 8 * x + 1] = g;
		world->window->data[y * world->window->width * world->window->bpp / 8
			+ world->window->bpp / 8 * x + 2] = r;
	}
}
