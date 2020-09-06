/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:32:13 by mnarazak          #+#    #+#             */
/*   Updated: 2020/08/31 23:41:42 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	put_spaces_char(t_printf *s_pf)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < s_pf->min_width - s_pf->current_width)
	{
		if (s_pf->iszero_flag)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
		i++;
	}
	return (ret);
}

static int	put_main_char(char *str, t_printf *s_pf)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < s_pf->current_width && str[i])
	{
		ret += write(1, str + i, 1);
		i++;
	}
	if (s_pf->isnull_str)
		free(str);
	return (ret);
}

int			print_char(t_printf *s_pf)
{
	int	ret;

	ret = 0;
	s_pf->current_width = 1;
	if (s_pf->isleft)
	{
		ret += ft_putchar(va_arg(s_pf->list, int));
		ret += put_spaces_char(s_pf);
	}
	else
	{
		ret += put_spaces_char(s_pf);
		ret += ft_putchar(va_arg(s_pf->list, int));
	}
	return (ret);
}

static int	print_str_main(char *str, t_printf *s_pf)
{
	int	ret;

	ret = 0;
	if (s_pf->isleft)
	{
		ret += put_main_char(str, s_pf);
		ret += put_spaces_char(s_pf);
	}
	else
	{
		ret += put_spaces_char(s_pf);
		ret += put_main_char(str, s_pf);
	}
	return (ret);
}

int			print_str(t_printf *s_pf)
{
	char	*str;

	if (!(str = va_arg(s_pf->list, char *)))
	{
		if (!(str = ft_strdup("(null)")))
		{
			s_pf->iserror = true;
			return (ERROR);
		}
		s_pf->isnull_str = true;
	}
	if ((int)ft_strlen(str) < s_pf->precision ||
				s_pf->precision == INIT_PRECISION)
		s_pf->current_width = (int)ft_strlen(str);
	else
		s_pf->current_width = s_pf->precision;
	return (print_str_main(str, s_pf));
}
