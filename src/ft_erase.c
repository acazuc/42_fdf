/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:14:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 08:18:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_erase(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->window->height)
	{
		x = 0;
		while (x < env->window->width)
		{
			pixel_put(env, x, y, 0);
			x++;
		}
		y++;
	}
}
