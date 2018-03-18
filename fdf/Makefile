# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pasnguye <pasnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 19:44:28 by pasnguye          #+#    #+#              #
#    Updated: 2018/03/16 01:25:10 by pasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	srcs/main.c \
		srcs/parse_file.c \
		srcs/trace_line.c \
		srcs/ft_is_int.c \
		srcs/events.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall# -g -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a .
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -L -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

%.o : %.c $(INCLUDE)
	gcc $(FLAGS) -c $< -o $@ 

clean:
	make -C libft clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all
