/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexpf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:01:51 by mlauer            #+#    #+#             */
/*   Updated: 2018/06/20 17:12:00 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int			ft_hexpf(t_arg *arg, va_list list)
{
	uintmax_t		n;
	char			*s;
	int				count;

	count = 0;
	n = ft_modpf(arg, list);
	if (arg->pres == 0 || 
}
