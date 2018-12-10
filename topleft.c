#include "fillit.h"

char	*bits_to_chars(unsigned short octet)
{
	int		i;
	int		j;
	char	*str;

	i = 0b1000000000000000;
	j = 15;
	str = ft_strnew(16);
	while (octet >= 0 && i)
	{
		str[j] = (octet / i) ? '#': '.';
		(octet / i) ? octet -= i : 0;
		i /= 2;
		--j;
	}
	return (str);
}

unsigned short	topleft(unsigned short bits)
{
	int		i;
	int		bit;

	i = 0;
	while (i != 15 && bit != 1)
	{
		bit = (bits & (1 << i)) ? 1 : 0;
		i++;
	}
	bits = bits >> (i - 1);
	if (check_tetrimino(bits_to_chars(bits)) == 1)
	{
		bits = bits << 1;
		if (check_tetrimino(bits_to_chars(bits)) == 1)
			bits = bits << 1;
	}
	return (bits);
}
