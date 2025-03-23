#include "fillit.h"

int	check_valid_tetris(char ***ptr)
{
	int	i;

	if (!ptr)
		return 0;
	i = 0;
	while(ptr[i])
	{
		if(ft_veclen(ptr[i]) > 4 || count_hash(ptr[i]) != 4)
			return 0;
		if(count_hash(ptr[i]) != 4)
			return 0;
		i++;
	}
	return 1;
}
