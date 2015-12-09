/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:36:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/08 08:49:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "error_quit.h"
#include "world.h"

void	window_init(t_world *world)
{
	int		loul;

	if (!(world->window->mlx = mlx_init()))
		error_quit("Failed to initializing mlx content");
	if (!(world->window->mlx_window = mlx_new_window(world->window->mlx
					, world->window->width
					, world->window->height, "acazuc's fdf")))
		error_quit("Failed to create window");
	world->window->bpp = 3 * 8;
	world->window->endian = 1;
	loul = world->window->width * world->window->bpp / 8;
	if (!(world->window->img = mlx_new_image(world->window->mlx
					, world->window->width, world->window->height)))
		error_quit("Failed to create image");
	if (!(world->window->data = mlx_get_data_addr(world->window->img
					, &(world->window->bpp), &loul
					, &(world->window->endian))))
		error_quit("Failed to get image data");
}
