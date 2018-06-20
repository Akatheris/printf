/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:29:44 by mlauer            #+#    #+#             */
/*   Updated: 2018/06/14 15:31:42 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int		get_conversion(t_arg *arg, const char *str, size_t *i)
{
	if (str[*i] == '%')
		(*i)++;
	if (!(ft_is_conversion(str[*i])))
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

int		get_width(t_arg *arg, const char *str, size_t *i)
{
	int		width;

	width = 0;
	if (str[*i] == '*')
		(*i)++;
	width = ft_atoi(&str[*i]);
	if (width)
	{
		if (str[*i] == '$')
			(*i)++;
		else 
			return (-1);
		arg->width = width;
	}
	return (0);
}
int		get_flag(t_arg *arg, const char *str, size_t *i)
{
	char	c;

	while (*i < arg->lenght)
	{
		c = str[*i];
		if (ft_is_flag(c))
		{
			if (c == '#')
				arg->flag = '#';
			else if (c == '0' && arg->flag != '-')
				arg->flag = '0';
			else if (c == '+')
				arg->flag = '+';
			else if (c == '-')
				arg->flag = '-';
			else if (c == ' ' && arg->flag != '+')
				arg->flag = ' ';
		}
		else
			return (-1);
		(*i)++;
	}
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
