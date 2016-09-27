/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:54:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 11:41:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "window.h"
# include "vector.h"
# include "map.h"

typedef struct			s_world
{
	t_vector			*position;
	t_vector			*rotation;
	t_window			*window;
	t_map				*map;
	int					lines;
	int					points;
	int					min;
	int					max;
	int					rotate_up;
	int					rotate_down;
	int					rotate_left;
	int					rotate_right;
	int					move_up;
	int					move_down;
	int					move_forward;
	int					move_backward;
	int					move_left;
	int					move_right;
}						t_world;

#endif
