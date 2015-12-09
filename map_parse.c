/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:28:50 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 09:01:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "error_quit.h"
#include "map.h"

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
			x = content[i + 1] == '\n' ? 0 : x;
			z = content[i + 1] == '\n' ? z + 1 : z;
			start = -1;
		}
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
			map->data[z][x] = 0;
			x++;
		}
		z++;
	}
	return (map_parse_part(map, content, -1, -1));
}
