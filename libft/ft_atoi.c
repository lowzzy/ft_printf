/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:28:43 by mnarazak          #+#    #+#             */
/*   Updated: 2020/07/21 22:51:37 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_delete_space(int i, const char *s)
{
	while ((s[i] == '\t') || (s[i] == '\n') || (s[i] == '\v')
			|| (s[i] == '\r') || (s[i] == '\f') || (s[i] == 32))
		i++;
	return (i);
}

int			ft_atoi(const char *s)
{
	int i;
	int ans;
	int isminus;

	isminus = 0;
	i = 0;
	ans = 0;
	i = ft_delete_space(i, s);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			isminus++;
		i++;
	}
	while ('0' <= s[i] && s[i] <= '9')
	{
		ans *= 10;
		ans += s[i] - '0';
		i++;
	}
	if (isminus == 1)
		return (-ans);
	return (ans);
}
