/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 06:55:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 11:38:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_listener(int keycode, void *param)
{
	t_world		*world;

	world = (t_world*)param;
	if (keycode == 53)
		exit(1);
	return (0);
}

int		expose_listener(void *param)
{
	t_world		*world;

	world = (t_world*)param;
	draw_reset(world);
	draw_map(world);
	draw_stats(world);
	return (0);
}
