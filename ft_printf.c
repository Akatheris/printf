int		ft_printf(const char *format, ...)
{
	va_list list;
	int result;

	va_start(list, format);
	result = ft_parse_format(format, list);
	va_end(list);
	return (result);
}
