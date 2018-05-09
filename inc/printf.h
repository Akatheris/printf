/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:17:12 by mlauer            #+#    #+#             */
/*   Updated: 2018/05/09 10:54:47 by mlauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
typedef struct s_string t_string;

struct			s_string
{
	const char		*str;
	int				len;
};
typedef struct s_arg t_arg;

struct			s_arg
{
	size_t			lenght;
	t_string		tstr;
	int				flag;
	int				width;
	int				pres;
	char			conversion;
	int				error;
	int				modif;		/* none = 0 / l = 1 / ll = 2 / h = 3 / hh = 4 / j = 5 / z = 6*/
};

int				ft_is_conversion(char c);
int				ft_is_modif(char c);
int				ft_is_flag(char c);
int				ft_is_pres(char c);
int				ft_is_valid(char c);
t_arg			ft_init_arg(const char *str, int len);
int				get_conversion(t_arg *arg, const char *str, size_t *i);
int				get_pres(t_arg *arg, const char *str, size_t *i);
int				get_width(t_arg *arg, const char *str, size_t *i);
int				get_flag(t_arg *arg, const char *str, size_t *i);
int				get_modif(t_arg *arg, const char *str, size_t *i);
#endif
