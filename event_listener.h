/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 06:59:39 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/28 07:04:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_LISTENER_H
# define FT_EVENT_LISTENER_H

int		mouse_listener(int button, int x, int y, void *param);
int		key_listener(int keycode, void *paran);
int		expose_listener(void *param);

#endif
