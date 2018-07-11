/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:22:16 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/11 15:11:53 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

void			ft_stringpf(t_arg *arg, va_list list)
{
	int		count;
	char	*s;
	size_t	len;

	len = 0;
	count = 0;
	s = va_arg(list, char *);
	len = ft_strlen(s);
	if (arg->pres > (int)len)
		arg->pres = len;
	ft_final_write(arg, s, 0, arg->pres);
}

static char		*ft_get_pre(t_arg *arg, int *sizep, char *pre)
{
	if (arg->conversion == 'x' || arg->conversion == 'X'
			|| arg->conversion == 'p')
	{
		*sizep = 2;
		if (arg->conversion == 'X')
			pre = "0X";
		else
			pre = "0X";
	}
	if (arg->conversion == 'o')
	{
		*sizep = 1;
		pre = "0";
	}
	return (pre);
}

int				ft_final_write(t_arg *arg, char *str, int finish, size_t pres)
{
	int		sizep;
	char	*pre;
	char	c;
	int		count;

	sizep = 0;
	if (arg->conversion != 'd' && arg->flag == 0)
		c = '0';
	else
		c = ' ';
	pre = ft_get_pre(arg, &sizep, pre);
	if (arg->conversion == 'o' && str && str[0] == '0')
		sizep = 0;
	arg->width -= sizep;
	if ((arg->flag != '-') && arg->width > 1)
		count += ft_write_loop(c, arg->width - pres);
	if (sizep != 0)
		ft_putstr(pre);
	ft_putstr(str);
	count += ft_strlen(str);
	if ((arg->flag == '-') && arg->width > 1)
		count += ft_write_loop(' ', arg->width - pres);
	if (finish)
		free((void*)str);
	return (count + sizep);
}
