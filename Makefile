# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2015/11/30 06:09:40 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRCS = fdf.c camera.c draw_line.c get_screen_coord.c new_point.c get_color.c event_listener.c load_map.c file_length.c get_file_content.c draw_map.c map_parse.c draw_stats.c movements.c world_init.c rotations.c error_quit.c world_free.c

OBJS = $(SRCS:.c=.o)

LIBRARY = -lm -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $^ $(LIBRARY)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
