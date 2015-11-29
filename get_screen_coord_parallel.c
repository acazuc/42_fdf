/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coord_parallel.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:06:08 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 15:06:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_screen_x(t_world *world, t_point *point)
{
	double		x_var;
	double		z_var;

	x_var = point->x * 50 * cos(world->rotation_y / 180.0 * 3.14);
	z_var = point->z * 50 * sin(world->rotation_y / 180.0 * 3.14);
	return (world->window_width / 2 + x_var + z_var);
}

int		get_screen_y(t_world *world, t_point *point)
{
	double		x_z_var;
	double		x_var;
	double		y_var;
	double		z_var;

	x_var = point->x * 50 * sin(world->rotation_y / 180.0 * 3.14);
	y_var = point->y * +5 * cos(world->rotation_x / 180.0 * 3.14);
	z_var = point->z * 50 * cos(world->rotation_y / 180.0 * 3.14);
	x_z_var = (z_var - x_var) * sin(world->rotation_x / 180.0 * 3.14);
	return (world->window_height / 2 + x_z_var + y_var);
}
