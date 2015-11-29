/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:43:22 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 13:56:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MOVEMENTS_H
# define FT_MOVEMENTS_H

# include "world.h"

void	step_forward(t_world *world);
void	step_backward(t_world *world);
void	step_left(t_world *world);
void	step_right(t_world *world);

#endif
