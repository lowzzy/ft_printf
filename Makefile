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

SOURCES =	src/print_diux.c\
			src/print_p.c\
			src/print_cs.c\
			src/print_percent.c\
			src/is_.c\
			src/ft_vprintf.c\
			src/ft_put_.c\
			src/ft_printf.c\
			src/switch_print.c\
			src/itohex.c\
			src/set_precision.c\
			src/set_flag.c\
			src/set_field.c\
			src/output.c\
			src/ft_uitoa.c\
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
