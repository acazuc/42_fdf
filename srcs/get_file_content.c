/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:08:27 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 08:19:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_file_content(char *file)
{
	char	*file_content;
	int		file_size;
	int		fd;

	file_size = file_length(file);
	if (!(file_content = malloc(sizeof(*file_content) * (file_size + 1))))
		error_quit("Failed to malloc file_content");
	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit("Failed to open map file");
	if (read(fd, file_content, file_size) == -1)
	{
		close(fd);
		error_quit("Failed to read map file");
	}
	file_content[file_size] = '\0';
	close(fd);
	return (file_content);
}
