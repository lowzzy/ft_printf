/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:31:27 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/04 16:52:51 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		flag_init(t_printf *s_pf)
{
	s_pf->isleft = false;
	s_pf->isminus = false;
	s_pf->iszero_flag = false;
	s_pf->isnull_str = false;
	s_pf->min_width = 0;
	s_pf->current_width = 0;
	s_pf->precision = INIT_PRECISION;
}

static char		*ft_vprintf_main(char *format, t_printf *s_pf, int *num)
{
	flag_init(s_pf);
	if (is_flag(format))
		format = set_flag(format, s_pf);
	if (is_field(format))
		format = set_field(format, s_pf);
	if (is_precision(format))
		format = set_precision(format + 1, s_pf);
	if (is_conversion(format))
	{
		*num += switch_print(format, s_pf);
		format++;
	}
	return (format);
}

int				ft_vprintf(char *format, t_printf *s_pf)
{
	int			num;

	num = 0;
	s_pf->iserror = false;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			num += ft_putchar(*format);
			format++;
		}
		if (*format == '%')
			format = ft_vprintf_main(format + 1, s_pf, &num);
	}
	if (s_pf->iserror)
		return (ERROR);
	else
		return (num);
}
