/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:54:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 08:58:37 by acazuc           ###   ########.fr       */
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
}						t_world;

#endif
