int	ft_get_base(char c)
{
	if (c == 'X' || c == 'x' || c == 'p')
		return (16);
	else if (c == 'o')
		return (8);
	else
		return (10);
}
