/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 06:55:32 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/07 13:53:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "draw_stats.h"
#include "draw_reset.h"
#include "movements.h"
#include "rotations.h"
#include "draw_map.h"
#include "world.h"

int		mouse_listener(int button, int x, int y, void *param)
{
	ft_putstr("Mouse event: {button: ");
	ft_putnbr(button);
	ft_putstr(", x: ");
	ft_putnbr(x);
	ft_putstr(", y: ");
	ft_putnbr(y);
	ft_putendl("}");
	param = NULL;
	return (0);
}

void	key_listener_moves(t_world *world, int key)
{
	if (key == 126)
		rotate_up(world);
	else if (key == 125)
		rotate_down(world);
	else if (key == 123)
		rotate_left(world);
	else if (key == 124)
		rotate_right(world);
	else if (key == 257)
		world->position->y -= 1;
	else if (key == 49)
		world->position->y += 1;
	else if (key == 13)
		step_forward(world);
	else if (key == 0)
		step_left(world);
	else if (key == 1)
		step_backward(world);
	else if (key == 2)
		step_right(world);
}

int		key_listener(int keycode, void *param)
{
	t_world		*world;

	world = (t_world*)param;
	ft_putstr("Keyboard event: {keycode: ");
	ft_putnbr(keycode);
	ft_putendl("}");
	if (keycode == 53)
		exit(1);
	if (keycode == 126 || keycode == 125 || keycode == 124
			|| keycode == 123 || keycode == 257 || keycode == 49
			|| keycode == 0 || keycode == 1 || keycode == 2
			|| keycode == 13)
	{
		draw_reset(world);
		key_listener_moves(world, keycode);
		draw_map(world);
		draw_stats(world);
	}
	return (0);
}

int		expose_listener(void *param)
{
	t_world		*world;

	world = (t_world*)param;
	draw_reset(world);
	draw_map(world);
	draw_stats(world);
	ft_putendl("Expose event");
	param = NULL;
	return (0);
}
