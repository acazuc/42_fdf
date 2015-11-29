/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coord.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:31:01 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 11:57:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_SCREEN_COORD_H
# define FT_GET_SCREEN_COORD_H

# include "point.h"
# include "world.h"

double	new_x(t_world *world, t_point *point);
double	new_y(t_world *world, t_point *point);
double	new_z(t_world *world, t_point *point);
int		get_screen_x(t_world *world, t_point *point);
int		get_screen_y(t_world *world, t_point *point);

#endif
