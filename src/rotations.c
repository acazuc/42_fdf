/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:54:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 11:46:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_loop(t_world *world)
{
	if (world->rotation->y >= 360)
		world->rotation->y -= 360;
	else if (world->rotation->y < 0)
		world->rotation->y += 360;
	if (world->rotation->x >= 360)
		world->rotation->x -= 360;
	else if (world->rotation->x < 0)
		world->rotation->x -= 360;
}

void			rotate_left(t_world *world)
{
	world->rotation->y += 2;
	check_loop(world);
}

void			rotate_right(t_world *world)
{
	world->rotation->y -= 2;
	check_loop(world);
}

void			rotate_up(t_world *world)
{
	world->rotation->x += 2;
	check_loop(world);
}

void			rotate_down(t_world *world)
{
	world->rotation->x -= 2;
	check_loop(world);
}
