#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmery <jmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:56:49 by jmery             #+#    #+#              #
#    Updated: 2014/01/19 19:26:04 by jmery            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB = srcs

FLAG = -Wall -Wextra -Werror

NAME = ft_ls

SRCS = $(LIB)/data.c \
	   $(LIB)/dir.c \
	   $(LIB)/ft_ls.c \
	   $(LIB)/ft_ls_2.c \
	   $(LIB)/ft_ls_3.c \
	   $(LIB)/info.c \
	   $(LIB)/info_2.c \
	   $(LIB)/options.c \
	   $(LIB)/path.c \
	   $(LIB)/print_info.c \
	   $(LIB)/table.c \
	   $(LIB)/table_2.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJS) -L. libft/libft.a

%.o: %.c
	gcc $(FLAG) -c $< -o $@ -I includes

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean all

