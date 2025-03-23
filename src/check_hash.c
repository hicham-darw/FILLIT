#include "fillit.h"

int	check_hash(char *str)
{
	if (!str)
		return (0);
	while(*str)
	{
		if(*str == '#')
			return 1;
		str++;
	}
	return 0;
}
