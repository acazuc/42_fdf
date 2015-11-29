/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:08:27 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 20:34:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "file_length.h"
#include "error_quit.h"
#include "world.h"

char	*get_file_content(t_world *world, char *file)
{
	char	*file_content;
	int		file_size;
	int		fd;

	file_size = file_length(world, file);
	if (!(file_content = malloc(sizeof(*file_content) * (file_size + 1))))
		error_quit(world
				, "Failed to malloc file_content (get_file_content.c:29)");
	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit(world, "Failed to open map file (get_file_content.c:31)");
	if (read(fd, file_content, file_size) == -1)
	{
		close(fd);
		error_quit(world, "Failed to read map file (get_file_content.c:35)");
	}
	file_content[file_size] = '\0';
	close(fd);
	return (file_content);
}
