static int	ft_verif_parse(const char *str, size_t *i, int *valid)
{
	if (str[i] == 0)
		return (1);
	while (str[*i] && ft_valid(str[*i]) && is_conversion (str[*i]))
		*i++;
	if ((*valid = str[*i] && ft_valid(str[*i])))
		*i++;
	else
		return (1);
	return (0);	

}

int	ft_parse_format(const char *str, va_list list)
{
	size_t	i;
	size_t	st;
	int	valid;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		start = i;
		valid = 0;
		if (str[i] == '%')
		{
			i++;
			ft_verif(str, &i, &valid);
		}
		else
			while (str[i] && str[i] != '%')
				i++;
		count += get_arg(&str[start], i - start, valid, list);
	}	
	return (count);
}
