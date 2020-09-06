/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:31:05 by mnarazak          #+#    #+#             */
/*   Updated: 2020/08/30 23:35:46 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf(char *format, ...)
{
	int			num;
	t_printf	s_pf;

	va_start(s_pf.list, format);
	num = ft_vprintf(format, &s_pf);
	va_end(s_pf.list);
	return (num);
}
