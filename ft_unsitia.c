/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:58:53 by mlauer            #+#    #+#             */
/*   Updated: 2018/04/05 15:29:44 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*		ft_unsitia(unsigned int n, int base)
{
	int					len;
	unsigned int		save;
	char				*str;
	char				basel[16]

	basel = "0123456789ABCDEF";
	save = n;
	len = 1;
	while (save /= base)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len--] = '\0';
	while (n >= base && len != -1)
	{
		str[len] = basel(n % base);
		n = n / base;
		len--;
	}
	return (str);
}

int main(void)
{
	ft_putendl(ft_unsitia(16,16);
	return 0;
}
