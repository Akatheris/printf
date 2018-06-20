/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:37:01 by mlauer            #+#    #+#             */
/*   Updated: 2018/06/06 15:19:14 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/printf.h"

static int			ft_verif_parse(const char *str, size_t *i, int *valid)
{
	if (str[*i] == 0)
		return (1);
	while (str[*i] && ft_is_valid(str[*i]) && ft_is_conversion (str[*i]))
		(*i)++;
	if ((*valid = str[*i] && ft_is_valid(str[*i])))
		(*i)++;
	else
		return (1);
	return (0);	

}

int				ft_parse(const char *str, va_list list)
{
	size_t		i;
	size_t		st;
	int			valid;
	int			count;

	i = 0;
	count = 0;
	while(str[i])
	{
		st = i;
		valid = 0;
		if (str[i] == '%')
		{
			i++;
			ft_verif_parse(str, &i, &valid);
		}
		else
			while (str[i] && str[i] != '%')
				i++;
	}	
	return (ft_get_arg(str,i - st));
}
