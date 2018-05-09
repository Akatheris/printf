/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:29:44 by mlauer            #+#    #+#             */
/*   Updated: 2018/05/02 18:25:26 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int		get_conversion(t_arg *arg, const char *str, size_t *i)
{
	if (ft_is_conversion(str[*i]))
			{
				arg->conversion = str[*i];
				(*i)++;
				return (0);
			}
	return (-1);
}

int		get_pres(t_arg *arg, const char *str, size_t *i)
{
	if (str[*i] != '.')
		return (-1);
	arg->pres = ft_atoi(&str[*i]);
	return (0);
}

int		get_flqg(t_arg *arg, const char *str, size_t *i)
{

	return (0);
}
int		get_modif(t_arg *arg, const char *str, size_t *i)
{
	arg->modif = 0;
	if (!ft_is_modif(str[*i]))
			return (-1);
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l' && (*i)++)
			arg->modif = 2;
		else
			arg ->modif = 1;
	}
	else if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h' && (*i)++)
				arg->modif = 4;
		else
			arg->modif = 3;
	}
	else if (str[*i] == 'j')
		arg->modif = 5;
	else if (str[*i] == 'z')
		arg->modif = 6;
	(*i)++;
	return (0);
}
