/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:42:44 by mlauer            #+#    #+#             */
/*   Updated: 2018/06/06 15:39:41 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

t_arg		ft_init_arg(const char *str, int len)
{
	t_arg		arg;

	arg.len = len;
	arg.str = str;
	arg.flag = 0;
	arg.width = 0;
	arg.pres = 0;
	arg.conversion = 0;
	arg.error = 0;
	arg.modif = 0;
	return (arg);
}
