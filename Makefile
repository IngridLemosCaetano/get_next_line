# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 21:11:58 by ingrid            #+#    #+#              #
#    Updated: 2025/08/30 18:26:53 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Como você precisará ler arquivos na sua get_next_line(), adicione esta opção no
# comando que chama o compilador: -D BUFFER_SIZE=n
NAME = get_next_line.a

CC = cc
SIZE = 42
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(SIZE)
AR = ar rcs
SRCS = 	get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean clean

.PHONY: all clean fclean re
