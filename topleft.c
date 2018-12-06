#include "fillit.h"

short	topleft(short byte)
{
	int		i;

	i = 16;
	if (((byte & (1 << 0) ? 1 : 0)) == 1)
		return (byte);
	while (((byte & (1 << i)) ? 1 : 0) != 1)
		i--;
	byte = byte >> (16 - (i + 1));
	return (byte);
}
