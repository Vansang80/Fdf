# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 19:44:28 by pasnguye          #+#    #+#              #
#    Updated: 2018/03/17 18:26:22 by pasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	srcs/main.c \
		srcs/parse_file.c \
		srcs/trace_line.c \
		srcs/events.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx
	mv libft/libft.a .
	mv minilibx/libmlx.a .
	gcc $(FLAGS) -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)
	rm -rf libmlx.a libft.a

%.o : %.c $(INCLUDE)
	gcc $(FLAGS) -c $< -o $@ 

clean:
	make -C libft clean
	make -C minilibx clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	make -C minilibx clean
	rm -rf $(NAME)

re : fclean all
