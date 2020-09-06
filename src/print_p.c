/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:32:30 by mnarazak          #+#    #+#             */
/*   Updated: 2020/08/31 23:39:51 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		put_spaces_p(t_printf *s_pf)
{
	int	i;

	i = 0;
	while (i < s_pf->min_width - s_pf->current_width)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

static int		put_main_p(char *str, t_printf *s_pf)
{
	if (s_pf->isnull_str && s_pf->precision != 0)
		return (write(1, "0", 1));
	else if (s_pf->isnull_str)
		return (0);
	return (ft_putstr(str));
}

static int		put_zeros_p(int digit, t_printf *s_pf)
{
	int	i;

	i = 0;
	if (digit >= s_pf->precision)
		return (0);
	else
	{
		while (i < s_pf->precision - digit)
		{
			write(1, "0", 1);
			i++;
		}
		return (i);
	}
}

static int		print_address_main(int digit, char *str, t_printf *s_pf)
{
	int	ret;

	ret = 0;
	if (s_pf->isleft)
	{
		ret += write(1, "0x", 2);
		ret += put_zeros_p(digit, s_pf);
		ret += put_main_p(str, s_pf);
		ret += put_spaces_p(s_pf);
	}
	else
	{
		ret += put_spaces_p(s_pf);
		ret += write(1, "0x", 2);
		ret += put_zeros_p(digit, s_pf);
		ret += put_main_p(str, s_pf);
	}
	free(str);
	return (ret);
}

int				print_address(t_printf *s_pf)
{
	unsigned long	num;
	int				digit;
	char			*str;

	if ((num = (unsigned long)va_arg(s_pf->list, void *)) == 0)
		s_pf->isnull_str = true;
	if (!(str = itohex(num, SMALL)))
	{
		s_pf->iserror = true;
		return (ERROR);
	}
	digit = ft_strlen(str);
	if (digit < s_pf->precision)
		s_pf->current_width = s_pf->precision + PREFIX_LEN;
	else
	{
		s_pf->current_width = digit + PREFIX_LEN;
		if (s_pf->isnull_str && s_pf->precision == 0)
			s_pf->current_width--;
	}
	return (print_address_main(digit, str, s_pf));
}
