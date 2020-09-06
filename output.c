/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:31:57 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/01 00:38:25 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	put_main(char *str, t_printf *s_pf)
{
	if (*str == '0' && s_pf->precision == 0 && s_pf->min_width == 0)
		return (0);
	else if (*str == '0' && s_pf->precision == 0)
		return (write(1, " ", 1));
	return (ft_putstr(str));
}

static int	put_zeros(int digit, t_printf *s_pf)
{
	int	i;
	int	ret;

	ret = 0;
	if (s_pf->isminus && (!s_pf->iszero_flag ||
(s_pf->iszero_flag && s_pf->precision != INIT_PRECISION)))
		ret += write(1, "-", 1);
	if (digit >= s_pf->precision)
		return (ret);
	else
	{
		i = 0;
		while (i++ < s_pf->precision - digit)
			ret += write(1, "0", 1);
		return (ret);
	}
}

static int	put_spaces_main(int ret, t_printf *s_pf)
{
	int	i;

	if (s_pf->min_width < s_pf->current_width)
		return (ret);
	else
	{
		i = 0;
		while (i++ < s_pf->min_width - s_pf->current_width)
		{
			if (s_pf->iszero_flag && s_pf->precision == INIT_PRECISION)
				ret += write(1, "0", 1);
			else
				ret += write(1, " ", 1);
		}
		return (ret);
	}
}

static int	put_spaces(int digit, t_printf *s_pf)
{
	int	ret;

	ret = 0;
	if (s_pf->iszero_flag && s_pf->isminus && s_pf->precision == INIT_PRECISION)
		ret += write(1, "-", 1);
	if (digit < s_pf->precision)
		s_pf->current_width = s_pf->precision;
	else
		s_pf->current_width = digit;
	if (s_pf->isminus)
		s_pf->current_width++;
	return (put_spaces_main(ret, s_pf));
}

int			output(int digit, char *str, t_printf *s_pf)
{
	int	ret;

	ret = 0;
	if (s_pf->isleft)
	{
		ret += put_zeros(digit, s_pf);
		ret += put_main(str, s_pf);
		ret += put_spaces(digit, s_pf);
	}
	else
	{
		ret += put_spaces(digit, s_pf);
		ret += put_zeros(digit, s_pf);
		ret += put_main(str, s_pf);
	}
	free(str);
	return (ret);
}
