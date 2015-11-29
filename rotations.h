/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:03:01 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 18:07:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROTATIONS_H
# define FT_ROTATIONS_H

# include "world.h"

void	rotate_left(t_world *world);
void	rotate_right(t_world *world);
void	rotate_up(t_world *world);
void	rotate_down(t_world *world);

#endif
