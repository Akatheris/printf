/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabpf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:06:32 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/11 14:58:28 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

static size_t			ft_get_size(int base, intmax_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

char					*ft_itoa_base(int base, intmax_t n, char sign, int len)
{
	char				*str;
	char				*basel;
	int					neg;

	neg = 0;
	basel = "0123456789";
	if ((str = (char*)malloc(sizeof(char) * len + neg + 1)) == NULL)
		return (NULL);
	if (sign)
	{
		str[0] = sign;
		neg = 1;
	}
	while (len > 0)
	{
		str[len + neg - 1] = basel[(n % base)];
		n = n / base;
		len--;
	}
	return (str);
}

char					*ft_itoa_base_st(t_arg *arg, char sign, intmax_t n)
{
	int			count;
	uintmax_t	v;
	int			base;
	int			neg;

	base = ft_get_base(arg->conversion);
	if (n < 0 || sign != 0)
		neg = 1;
	count = ft_get_size(10, n);
	if (count < arg->pres)
		count = arg->pres;
	if (count < arg->width - neg)
		count = arg->width - neg;
	if (n < 0)
	{
		v = n * -1;
		sign = '-';
	}
	else
		v = n;
	return (ft_itoa_base(base, v, sign, count));
}
