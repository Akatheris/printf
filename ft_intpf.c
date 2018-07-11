/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intpf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:32:07 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/11 15:09:38 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

static intmax_t			ft_modifpf(t_arg *arg, va_list list)
{
	intmax_t n;

	n = 0;
	if (arg->modif == 1)
		n = va_arg(list, long);
	else if (arg->modif == 2)
		n = va_arg(list, long long);
	else if (arg->modif == 3)
		n = (short)n;
	else if (arg->modif == 4)
		n = (char)n;
	else if (arg->modif == 5)
		n = va_arg(list, intmax_t);
	else if (arg->modif == 6)
		n = va_arg(list, ssize_t);
	else
		n = va_arg(list, int);
	return (n);
}

int						ft_flagpf(t_arg *arg, va_list list)
{
	intmax_t	n;
	char		*s;
	int			count;
	char		sign;

	count = 0;
	n = ft_modifpf(arg, list);
	if (arg->flag == '+')
		sign = '+';
	else if (arg->flag == ' ')
		sign = ' ';
	else
		sign = 0;
	if (n == 0 && arg->pres == 0)
		s = NULL;
	else
		s = ft_itoa_base_st(arg, sign, n);
	count += ft_final_write(arg, s, 0, arg->pres);
	return (count);
}

static intmax_t			ft_umodifpf(t_arg *arg, va_list list)
{
	intmax_t n;

	n = 0;
	if (arg->modif == 1)
		n = va_arg(list, unsigned long);
	else if (arg->modif == 2)
		n = va_arg(list, unsigned long long);
	else if (arg->modif == 3)
		n = (unsigned short)n;
	else if (arg->modif == 4)
		n = (unsigned char)n;
	else if (arg->modif == 5)
		n = va_arg(list, uintmax_t);
	else if (arg->modif == 6)
		n = va_arg(list, size_t);
	else
		n = va_arg(list, unsigned int);
	return (n);
}

int						ft_intpf(t_arg *arg, va_list list)
{
	uintmax_t		n;
	char			*s;
	int				caps;
	int				count;

	count = 0;
	caps = 0;
	if (arg->conversion == 'd')
		return (ft_flagpf(arg, list));
	n = ft_umodifpf(arg, list);
	if (ft_islower(arg->conversion))
		caps = 1;
	if ((arg->pres == 0 && n == 0) || (n == 0 && arg->conversion != 0)
			|| (arg->flag == '#'))
		s = NULL;
	else
		s = ft_uitoa_base_st(arg, n, (caps == 1 ? "0123456789ABCDEF"
					: "0123456789abcdef"));
	count += ft_final_write(arg, s, 0, arg->pres);
	return (count);
}
