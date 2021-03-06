/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:12:19 by mlauer            #+#    #+#             */
/*   Updated: 2018/07/11 15:12:47 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int				ft_get_arg(const char *str, size_t len)
{
	static int		(*ft[5])(t_arg *arg, const char *str, size_t *i) = {
					get_conversion, get_pres, get_width, get_flag, get_modif};
	t_arg			arg;
	size_t			i;
	size_t			ftc;
	intmax_t		n;

	i = 0;
	ftc = 0;
	arg = ft_init_arg(str, len);
	while (ftc < 5)
	{
		if ((*ft[ftc])(&arg, str, &i))
		{
			arg.error = -1;
			break ;
		}
		ftc++;
	}
	if (arg.conversion == 'i')
		arg.conversion = 'd';
	return (0);
}
