/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:32:56 by mnarazak          #+#    #+#             */
/*   Updated: 2020/08/31 23:19:57 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*set_flag(char *format, t_printf *s_pf)
{
	while (*format == '0' || *format == '-')
	{
		if (*format == '0')
		{
			s_pf->iszero_flag = true;
			format++;
		}
		if (*format == '-')
		{
			s_pf->isleft = true;
			format++;
		}
	}
	if (s_pf->iszero_flag && s_pf->isleft)
		s_pf->iszero_flag = false;
	return (format);
}
