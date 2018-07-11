/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:01:10 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/09 16:16:36 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int		ft_write_loop(const char c, int i)
{
	int		z;

	z = 0;
	while (z < i)
	{
		ft_putchar(c);
		z++;
	}
	return (z);
}
