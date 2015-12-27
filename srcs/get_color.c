/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:36:18 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 17:07:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "../libft/libft.h"

int		get_color(t_point *point)
{
	int		part;

	if (point->y < -2)
		return (0xFF0000);
	else if (point->y < 0)
	{
		part = 0x00FF00 / 2.0 * (2.0 + point->y);
		return (0xFF0000 + part - part % 0x000100);
	}
	else if (point->y < 2)
		return (0xFFFF00 + 0x0000FF * point->y / 2.0);
	return (0xFFFFFF);
}
