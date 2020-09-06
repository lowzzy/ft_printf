/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:32:48 by mnarazak          #+#    #+#             */
/*   Updated: 2020/08/31 23:19:40 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*set_field(char *format, t_printf *s_pf)
{
	char	*last_address;
	int		i;

	if (*format == '*')
	{
		s_pf->min_width = va_arg(s_pf->list, int);
		last_address = format + 1;
		if (s_pf->min_width < 0)
		{
			s_pf->isleft = true;
			s_pf->min_width *= -1;
			if (s_pf->iszero_flag)
				s_pf->iszero_flag = false;
		}
	}
	else
	{
		i = 0;
		while (ft_isdigit(format[i]))
			i++;
		s_pf->min_width = ft_atoi(format);
		last_address = format + i;
	}
	return (last_address);
}
