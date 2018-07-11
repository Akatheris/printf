/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charpf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:34:06 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/11 14:45:49 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int		ft_charpf(t_arg *arg, va_list list)
{
	int		count;
	int		c;
	char	p;

	if (arg->flag == '0')
		p = '0';
	else
		p = ' ';
	c = va_arg(list, int);
	if ((arg->flag == '-') && arg->width > 1)
		count += ft_write_loop(p, arg->width - 1);
	ft_putchar(c);
	count++;
	if ((arg->flag != '-') && arg->width > 1)
		count += ft_write_loop(' ', arg->width - 1);
	return (count);
}
