char	*get_uniques_char(char *str)
{
	char 	symbol[20];
	int		b_exist;
	int		i_s;
	int		i;

	i = 0;
	while (str[i])
	{
		b_exist = 0;
		i_s = 0;
		while (symbol[i_s])
		{
			if (str[i] == symbol[i_s])
				b_exist = 1;
			i_s++;
		}
		if (!b_exist)
		{
			symbol[i_s] = str[i];
			ft_putchar_fd(symbol[i_s], 1);
		}
		i++;
	}
	return (symbol);
}