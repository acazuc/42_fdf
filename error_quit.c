/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:32:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 20:19:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "world_free.h"
#include "world.h"

void	error_quit(t_world *world, char *error_message)
{
	ft_putstr("Error happened: ");
	ft_putendl(error_message);
	world_free(world);
	exit(-1);
}
