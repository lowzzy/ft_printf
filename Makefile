# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/30 23:30:52 by mnarazak          #+#    #+#              #
#    Updated: 2020/08/30 23:30:59 by mnarazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rc
NAME = libftprintf.a

SOURCES =	print_diux.c\
			print_p.c\
			print_cs.c\
			print_percent.c\
			is_.c\
			ft_vprintf.c\
			ft_put_.c\
			ft_printf.c\
			switch_print.c\
			itohex.c\
			set_precision.c\
			set_flag.c\
			set_field.c\
			output.c\
			ft_uitoa.c\
			libft/ft_itoa.c\
			libft/ft_isdigit.c\
			libft/ft_memmove.c\
			libft/ft_strdup.c\
			libft/ft_strlen.c\
			libft/ft_toupper.c\
			libft/ft_atoi.c\


OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
