/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:33:03 by mnarazak          #+#    #+#             */
/*   Updated: 2020/08/31 23:20:21 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*set_precision(char *format, t_printf *s_pf)
{
	char	*last_address;
	int		i;

	if (is_conversion(format))
	{
		s_pf->precision = 0;
		return (format);
	}
	if (*format == '*')
	{
		if ((s_pf->precision = va_arg(s_pf->list, int)) < 0)
			s_pf->precision = -1;
		last_address = format + 1;
	}
	else
	{
		i = 0;
		while (ft_isdigit(format[i]))
			i++;
		s_pf->precision = ft_atoi(format);
		last_address = format + i;
	}
	return (last_address);
}
