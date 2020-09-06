/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:42:47 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/01 00:35:43 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LARGE	true
# define SMALL	false
# define ERROR	-1
# define ERROR_FORMAT	NULL
# define PREFIX_LEN	2
# define INIT_PRECISION	-1
# define INT_MIN	-2147483648
# define INT_MIN_DIGIT	10

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_printf
{
	va_list		list;
	bool		isleft;
	bool		isminus;
	bool		iszero_flag;
	bool		isnull_str;
	bool		iserror;
	int			min_width;
	int			precision;
	int			current_width;
	char		conversion;
}				t_printf;

char			*ft_itoa(int n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
int				ft_toupper(int c);
int				ft_atoi(const char *s);
int				ft_isdigit(int n);
char			*itohex(unsigned long decimal, bool islarge);
char			*ft_uitoa(unsigned int n);
int				ft_printf(char *format, ...);
int				ft_vprintf(char *format, t_printf *s_pf);
int				ft_putstr(char *str);
int				ft_putchar(char c);
int				switch_print(char *format, t_printf	*s_pf);
int				output(int digit, char *str, t_printf *s_pf);
char			*set_field(char *format, t_printf *s_pf);
char			*set_precision(char *format, t_printf *s_pf);
char			*set_flag(char *format, t_printf *s_pf);
int				print_char(t_printf *s_pf);
int				print_str(t_printf *s_pf);
int				print_decimal(t_printf *s_pf);
int				print_hex(t_printf *s_pf);
int				print_hex_large(t_printf *s_pf);
int				print_unsigned(t_printf *s_pf);
int				print_address(t_printf *s_pf);
int				print_percent(t_printf *s_pf);
bool			is_conversion(char *format);
bool			is_field(char *format);
bool			is_precision(char *format);
bool			is_flag(char *format);

#endif
