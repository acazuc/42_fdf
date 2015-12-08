/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:24:08 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/07 13:47:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel_put.h"
#include "world.h"

void	draw_reset(t_world *world)
{
	int		x;
	int		y;

	y = 0;
	while (y < world->window->height)
	{
		x = 0;
		while (x < world->window->width)
		{
			pixel_put(world, x, y, 0);
			x++;
		}
		y++;
	}
}
