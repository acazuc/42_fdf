/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:54:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 08:20:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(double x, double y, double z)
{
	t_point		*point;

	if (!(point = malloc(sizeof(t_point))))
		error_quit("Failed to malloc point");
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}
