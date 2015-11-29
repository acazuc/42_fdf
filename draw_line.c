/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:25:27 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 20:31:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "get_screen_coord.h"
#include "minilibx/mlx.h"
#include "error_quit.h"
#include "get_color.h"
#include "world.h"
#include "point.h"
#include "line.h"

static void	draw_line_part(t_world *world, t_line *line)
{
	t_point		*point;
	double		ratio;
	double		x;
	double		y;

	if (!(point = malloc(sizeof(t_point))))
		error_quit(world, "Failed to malloc point struct (draw_line.c:31)");
	ratio = 0;
	while (ratio <= 1)
	{
		x = line->org_x + line->dx * ratio;
		point->y = line->p1->y + (line->p2->y - line->p1->y) * ratio;
		y = line->org_y + line->dy * ratio;
		mlx_pixel_put(world->window->mlx, world->window->mlx_window, x, y
				, get_color(point));
		ratio += 1.0 / line->length;
	}
	free(point);
}

void		draw_line(t_world *world, t_point *p1, t_point *p2)
{
	t_line	*line;

	if (new_z(world, p2) >= 1 && new_z(world, p1) >= 1)
	{
		if (!(line = malloc(sizeof(*line))))
			error_quit(world, "Failed to malloc line struct (draw_line.c:52)");
		line->dest_x = get_screen_x(world, p2);
		line->dest_y = get_screen_y(world, p2);
		line->org_x = get_screen_x(world, p1);
		line->org_y = get_screen_y(world, p1);
		line->dx = line->dest_x - line->org_x;
		line->dy = line->dest_y - line->org_y;
		line->length = sqrt(pow(line->dx, 2) + pow(line->dy, 2));
		line->p1 = p1;
		line->p2 = p2;
		draw_line_part(world, line);
		free(line);
	}
}
