/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:14:13 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/09 16:11:56 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int		ft_printf(const char *format, ...)
{
	va_list list;
	int result;

	va_start(list, format);
	result = ft_parse(format, list);
	va_end(list);
	return (result);
}
