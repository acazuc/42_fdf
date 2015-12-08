# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2015/12/07 13:54:08 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -Ofast

SRCS = fdf.c camera.c draw_line.c get_screen_coord.c new_point.c get_color.c event_listener.c load_map.c file_length.c get_file_content.c draw_map.c map_parse.c draw_stats.c movements.c world_init.c rotations.c error_quit.c draw_reset.c pixel_put.c window_init.c

OBJS = $(SRCS:.c=.o)

LIBRARY = -lm -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit

all: libft $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $^ $(LIBRARY)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

.PHONY: clean fclean re libft

libft:
	@(cd libft/; make)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
