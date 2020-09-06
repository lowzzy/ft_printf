/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:42:44 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/01 14:42:48 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				print_decimal(t_printf *s_pf)
{
	int		num;
	char	*str;

	if ((num = va_arg(s_pf->list, int)) == INT_MIN)
	{
		s_pf->isminus = true;
		if (!(str = ft_strdup("2147483648")))
		{
			s_pf->iserror = true;
			return (ERROR);
		}
		return (output(INT_MIN_DIGIT, str, s_pf));
	}
	else if (num < 0)
	{
		s_pf->isminus = true;
		num *= (-1);
	}
	if (!(str = ft_itoa(num)))
	{
		s_pf->iserror = true;
		return (ERROR);
	}
	return (output(ft_strlen(str), str, s_pf));
}

int				print_hex(t_printf *s_pf)
{
	unsigned int	num;
	char			*str;
	int				digit;

	num = va_arg(s_pf->list, unsigned int);
	if (!(str = itohex(num, SMALL)))
	{
		s_pf->iserror = true;
		return (ERROR);
	}
	digit = ft_strlen(str);
	return (output(digit, str, s_pf));
}

int				print_hex_large(t_printf *s_pf)
{
	unsigned int	num;
	char			*str;
	int				digit;

	num = va_arg(s_pf->list, unsigned int);
	if (!(str = itohex(num, LARGE)))
	{
		s_pf->iserror = true;
		return (ERROR);
	}
	digit = ft_strlen(str);
	return (output(digit, str, s_pf));
}

int				print_unsigned(t_printf *s_pf)
{
	unsigned int	num;
	int				digit;
	char			*str;

	num = va_arg(s_pf->list, unsigned int);
	if (!(str = ft_uitoa(num)))
	{
		s_pf->iserror = true;
		return (ERROR);
	}
	digit = ft_strlen(str);
	return (output(digit, str, s_pf));
}
