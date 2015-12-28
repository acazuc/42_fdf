/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:46:11 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 12:55:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid_chars(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '-' && map[i] != '\n' && map[i] != ' '
				&& (map[i] < '0' || map[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	get_map_height(char *map)
{
	int		count;
	int		i;

	count = 1;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	get_map_width(char *map)
{
	int		maximum;
	int		count;
	int		i;

	maximum = -1;
	count = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == '-' || (map[i] >= '0' && map[i] <= '9'))
		{
			if (i == 0 || map[i - 1] == ' ' || map[i - 1] == '\n')
				count++;
		}
		else if (map[i] == '\n')
		{
			if (count > maximum)
				maximum = count;
			count = 0;
		}
	}
	return (maximum);
}

void		load_map(t_world *world, char *file)
{
	char	*map_content;

	map_content = get_file_content(file);
	if (!is_valid_chars(map_content))
		error_quit(ft_strcat("Map isn't a valid map (only map with [0-9 "
					, "-\\n\\0] charcters allowed"));
	if (!(world->map = malloc(sizeof(*(world->map)))))
		error_quit("Failed to malloc map struct");
	world->map->height = get_map_height(map_content);
	world->map->width = get_map_width(map_content);
	if (!map_parse(world->map, map_content))
		error_quit("Failed to parse map");
	free(map_content);
}
