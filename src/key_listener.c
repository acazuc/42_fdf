/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:28:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 12:37:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press_listener(int key, void *data)
{
	t_world		*world;

	world = (t_world*)data;
	if (key == 53)
		exit(0);
	if (key == 126)
		world->rotate_up = 1;
	else if (key == 125)
		world->rotate_down = 1;
	else if (key == 123)
		world->rotate_left = 1;
	else if (key == 124)
		world->rotate_right = 1;
	else if (key == 257)
		world->move_down = 1;
	else if (key == 49)
		world->move_up = 1;
	else if (key == 13)
		world->move_forward = 1;
	else if (key == 0)
		world->move_left = 1;
	else if (key == 1)
		world->move_backward = 1;
	else if (key == 2)
		world->move_right = 1;
	return (0);
}

int	key_release_listener(int key, void *data)
{
	t_world		*world;

	world = (t_world*)data;
	if (key == 126)
		world->rotate_up = 0;
	else if (key == 125)
		world->rotate_down = 0;
	else if (key == 123)
		world->rotate_left = 0;
	else if (key == 124)
		world->rotate_right = 0;
	else if (key == 257)
		world->move_down = 0;
	else if (key == 49)
		world->move_up = 0;
	else if (key == 13)
		world->move_forward = 0;
	else if (key == 0)
		world->move_left = 0;
	else if (key == 1)
		world->move_backward = 0;
	else if (key == 2)
		world->move_right = 0;
	return (0);
}
