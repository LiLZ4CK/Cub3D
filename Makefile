# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 19:54:07 by zwalad            #+#    #+#              #
#    Updated: 2023/01/05 16:06:15 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

CC := @gcc

FLAGS :=  -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror  

HEADER = cub1d.h

RM = @rm -rf

SOURCE := main.c\
			submain.c\
			libft.c\
			get/get_next_line.c\
			get/get_next_line_utils.c\
			minimap.c\
			map_init.c\
			map_init2.c\
			map_init3.c\
			moves.c\
			src/get_dis.c \
			src/get_3d_wall.c \
			src/raycasting_help.c \
			src/init_data.c \
			src/init_data2.c \
			player_init.c\

OBJCT = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME) : $(OBJCT) $(HEADER)
	$(CC) $(SOURCE)  $(FLAGS) -o $(NAME)

clean: 
	$(RM) $(OBJCT)

fclean: clean
	$(RM) $(NAME)

re: fclean all