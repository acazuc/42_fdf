/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:54:15 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/08 08:08:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WORLD_H
# define FT_WORLD_H

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
}						t_world;

#endif
