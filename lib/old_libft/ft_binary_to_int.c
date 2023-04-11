int     ft_binary_to_int(char *binary, int bits_number)
{
	int     i;
	int    num;

	i = 0;
	num = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			num |= 1 << ((bits_number - 1) - i);
		i++;
	}
	return (num);
}