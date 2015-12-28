/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:36:37 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 08:19:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		move(t_world *world, float angle)
{
	angle = world->rotation->y + angle;
	world->position->x += cos(-angle / 180.0 * 3.14);
	world->position->z += sin(-angle / 180.0 * 3.14);
}

void			step_forward(t_world *world)
{
	move(world, 90);
}

void			step_backward(t_world *world)
{
	move(world, -90);
}

void			step_left(t_world *world)
{
	move(world, 180);
}

void			step_right(t_world *world)
{
	move(world, 0);
}
