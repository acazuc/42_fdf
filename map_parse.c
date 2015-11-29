/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:28:50 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 19:34:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
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

	map->data = malloc(sizeof(*(map->data)) * map->height);
	z = 0;
	printf("Height: %d, width: %d\n", map->height, map->width);
	while (z < map->height)
	{
		map->data[z] = malloc(sizeof(**(map->data)) * map->width);
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
