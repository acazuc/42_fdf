/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:00:44 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 20:06:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "error_quit.h"
#include "world.h"

int		file_length(t_world *world, char *file)
{
	char	*buffer;
	int		readed;
	int		size;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit(world, "Failed to open map file (file_length.c:27)");
	if (!(buffer = malloc(sizeof(*buffer) * 100000)))
		error_quit(world, "Failed to malloc buffer (file_length.c:29)");
	size = 0;
	while ((readed = read(fd, buffer, 100000)) > 0)
		size += readed;
	close(fd);
	free(buffer);
	if (readed == -1)
		error_quit(world, "Failed to read map file (file_length.c:36)");
	return (size);
}
