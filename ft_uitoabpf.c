/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:06:18 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/11 15:03:57 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

static size_t	ft_get_size(int base, intmax_t n)
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

char			*ft_uitoa_base(int base, uintmax_t n, int len, char *basel)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (len > 0)
	{
		str[len] = basel[(n % base)];
		n = n / base;
		len--;
	}
	return (str);
}

char			*ft_uitoa_base_st(t_arg *arg, uintmax_t n, char *basel)
{
	int					count;
	uintmax_t			v;
	int					base;

	base = ft_get_base(arg->conversion);
	count = ft_get_size(10, n);
	if (count < arg->pres)
		count = arg->pres;
	if (count < arg->width)
		count = arg->width;
	v = n;
	return (ft_uitoa_base(base, v, count, basel));
}
