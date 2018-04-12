/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:17:12 by mlauer            #+#    #+#             */
/*   Updated: 2018/04/12 15:26:26 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
typedef struct s_string t_string;

struct			s_string
{
	char		*str;
	int			len;
};
typedef struct s_arg t_arg;

struct			s_arg
{
	t_string	tstr;
	int			flags;
	int			width;
	int			presicion;
	char		converstion;
	int			error;
};

#endif
