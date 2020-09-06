/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:41:39 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/01 00:42:07 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	count_ui_digit(unsigned int num)
{
	unsigned int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num >= 1)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*main_uitoa(unsigned int n, char *str)
{
	unsigned int	tmp;
	unsigned int	time;

	time = 0;
	while (n > 0)
	{
		ft_memmove(str + 1, str, time + 1);
		tmp = (n % 10);
		n /= 10;
		str[0] = tmp + '0';
		time++;
	}
	return (str);
}

char		*ft_uitoa(unsigned int n)
{
	char	*str;

	if (!(str = (char *)malloc(count_ui_digit(n) + 1)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = main_uitoa(n, str);
	str[count_ui_digit(n)] = '\0';
	return (str);
}
