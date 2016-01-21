/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:28:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 13:15:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		map_check(t_map *map, char *content)
{
	int		current_width;
	int		i;

	current_width = 0;
	i = -1;
	while (content[++i])
	{
		if (content[i] == '-' || (content[i] >= '0' && content[i] <= '9'))
		{
			if (i == 0 || content[i - 1] == ' ' || content[i - 1] == '\n')
				current_width++;
		}
		else if (content[i] == '\n')
		{
			if (current_width != map->width)
				return (0);
			current_width = 0;
		}
	}
	return (1);
}

static int		map_parse_part(t_map *map, char *content, int i, int start)
{
	char	*substr;
	int		x;
	int		z;

	x = 0;
	z = 0;
	while (content[++i])
	{
		if ((content[i] == '-' || (content[i] >= '0' && content[i] <= '9'))
				&& (i == 0 || content[i - 1] == ' ' || content[i - 1] == '\n'))
			start = i;
		if (start != -1 && (content[i + 1] == '\0' || content[i + 1] == '\n'
						|| content[i + 1] == ' '))
		{
			if (!(substr = ft_strsub(content, start, i - start + 1)))
				return (0);
			map->data[z][x++] = ft_atoi(substr);
			free(substr);
			start = -1;
		}
		z = content[i] == '\n' ? z + 1 : z;
		x = content[i] == '\n' ? 0 : x;
	}
	return (1);
}

int				map_parse(t_map *map, char *content)
{
	int		x;
	int		z;

	if (!(map->data = malloc(sizeof(*(map->data)) * map->height)))
		error_quit("Failed to malloc map");
	z = 0;
	while (z < map->height)
	{
		if (!(map->data[z] = malloc(sizeof(**(map->data)) * map->width)))
			error_quit("Failed to malloc map");
		x = 0;
		while (x < map->width)
		{
			map->data[z][x] = 127;
			x++;
		}
		z++;
	}
	return (map_check(map, content) && map_parse_part(map, content, -1, -1));
}
