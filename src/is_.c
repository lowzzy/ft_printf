/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:31:38 by mnarazak          #+#    #+#             */
/*   Updated: 2020/08/31 23:14:51 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool	is_conversion(char *format)
{
	if (*format == 'c' || *format == 's' || *format == 'p' ||
	*format == 'd' || *format == 'i' || *format == 'u' ||
	*format == 'x' || *format == 'X' || *format == '%')
		return (true);
	return (false);
}

bool	is_field(char *format)
{
	if (ft_isdigit(*format) || *format == '*')
		return (true);
	return (false);
}

bool	is_precision(char *format)
{
	if (*format == '.')
		return (true);
	return (false);
}

bool	is_flag(char *format)
{
	if (*format == '0' || *format == '-')
		return (true);
	return (false);
}
