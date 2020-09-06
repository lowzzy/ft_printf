/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:39:54 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/01 00:39:57 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	switch_print(char *format, t_printf *s_pf)
{
	if (*format == 'c')
		return (print_char(s_pf));
	else if (*format == 's')
		return (print_str(s_pf));
	else if (*format == 'd' || *format == 'i')
		return (print_decimal(s_pf));
	else if (*format == 'x')
		return (print_hex(s_pf));
	else if (*format == 'X')
		return (print_hex_large(s_pf));
	else if (*format == 'u')
		return (print_unsigned(s_pf));
	else if (*format == 'p')
		return (print_address(s_pf));
	else if (*format == '%')
		return (print_percent(s_pf));
	return (0);
}
