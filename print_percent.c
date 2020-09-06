/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:32:39 by mnarazak          #+#    #+#             */
/*   Updated: 2020/09/03 14:46:08 by mnarazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_percent(t_printf *s_pf)
{
	char *str;

	if (!(str = ft_strdup("%")))
	{
		s_pf->iserror = true;
		return (ERROR);
	}
	return (output(1, str, s_pf));
}
