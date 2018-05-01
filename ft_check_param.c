/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:53:28 by mlauer            #+#    #+#             */
/*   Updated: 2018/04/12 16:12:10 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/printf.h"

int		ft_is_conversion(char c)
{
	if (ft_strfind("sSpdDioOuUxXcC%", c))
			return (-1);
	return (0);
}

int		ft_is_modif(char c)
{
	if (ft_strfind("hljz", c))
		return (-1);
	return (0);
}

int		ft_is_flag(char c)
{
	if (ft_strfind("#0-+ ", c))
		return (-1);
	return(0);
}

int		ft_is_pres(char c)
{
	if (ft_strfind("$*.", c))
		return(-1);
	return (0);
}
