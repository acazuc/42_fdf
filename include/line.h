/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 07:03:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:27:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "point.h"

typedef struct		s_line
{
	double			length;
	double			dest_x;
	double			dest_y;
	double			org_x;
	double			org_y;
	double			dx;
	double			dy;
	t_point			*p1;
	t_point			*p2;
}					t_line;

#endif
