/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 08:02:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/22 09:06:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "world.h"
# include "point.h"
# include "map.h"

void	draw_line(t_world *world, t_point *p1, t_point *p2);
void	draw_map(t_world *world);
void	draw_reset(t_world *world);
void	draw_stats(t_world *world);
void	error_quit(char *error_message);
int		key_listener(int keycode, void *param);
int		expose_listener(void *param);
int		file_length(char *file);
int		get_color(t_world *world, t_point *point);
char	*get_file_content(char *file);
double	new_x(t_world *world, t_point *point);
double	new_y(t_world *world, t_point *point);
double	new_z(t_world *world, t_point *point);
int		get_screen_x(t_world *world, t_point *point);
int		get_screen_y(t_world *world, t_point *point);
void	load_map(t_world *world, char *file);
int		map_parse(t_map *map, char *content);
void	step_forward(t_world *world);
void	step_backward(t_world *world);
void	step_left(t_world *world);
void	step_right(t_world *world);
t_point	*new_point(double x, double y, double z);
void	pixel_put(t_world *world, int x, int y, unsigned int color);
void	rotate_left(t_world *world);
void	rotate_right(t_world *world);
void	rotate_up(t_world *world);
void	rotate_down(t_world *world);
void	window_init(t_world *world);
void	world_init_positions(t_world *world);
void	world_init(t_world *world);
void	get_min_max(t_world *world);

#endif
