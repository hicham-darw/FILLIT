#include "fillit.h"

int	check_valid_tetris(char **ptr)
{
	int	i, j, hashtag;
	
	if (!ptr)
		return 0;
	i = 0;
	while(ptr[i])
	{
		j = i + 4;
		if((hashtag = count_hash(ptr, i, j)) != 4 || ft_strlen(ptr[i]) != 4)
			return 0;
		i+=4;
	}
	return 1;
}
