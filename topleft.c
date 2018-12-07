#include "fillit.h"

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
	return (bits);
}
