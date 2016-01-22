/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:36:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 09:07:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_world *world, t_point *point)
{
	int		part;

	if (point->y <= world->min)
		return (0xFF0000);
	if (point->y >= world->max)
		return (0xFFFF00);
	part = 0x00FF00 * (double)(point->y - world->min)
		/ (double)(world->max - world->min);
	return (0xFF0000 + part - part % 0x000100);
}
