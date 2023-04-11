#include<stdio.h>
#include "libft.h"

int		*ft_int_to_binary(int dec, int bit_number)
{
	int	i;
	int	*binary;

	i = bit_number - 1;
	binary = ft_calloc(bit_number + 1, sizeof(int));
	while (dec > 0)
	{
		binary[i] = dec % 2;
		dec  /= 2;
		i--;
	}
	/* ---------------------------------- DEBUG --------------------------------- */
	// i = 0;
	// while (i < (bit_number))
	// {
	// 	printf("|%i", binary[i]);
	// 	i++;
	// }
	// printf("\n----------------\n");
	/* ---------------------------------- DEBUG --------------------------------- */
	return (binary);
}