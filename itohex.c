/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:31:48 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/04 16:45:19 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	count_digit(unsigned long num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num >= 1)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static char	change_to_hex(unsigned long num)
{
	if (0 <= num && num <= 9)
		return ('0' + num);
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else if (num == 15)
		return ('f');
	else
		return (0);
}

char		*itohex(unsigned long decimal, bool islarge)
{
	char	*hex;
	int		i;
	char	tmp;
	int		len;

	len = count_digit(decimal);
	if (!(hex = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	hex[len] = '\0';
	i = 1;
	while (i <= len)
	{
		if (islarge)
			tmp = ft_toupper(change_to_hex(decimal % 16));
		else
			tmp = change_to_hex(decimal % 16);
		decimal /= 16;
		hex[len - i] = tmp;
		i++;
	}
	return (hex);
}
