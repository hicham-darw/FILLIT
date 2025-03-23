#include "fillit.h"

size_t	len_tetris_and_str(char **vec, int *first, int *last)
{
	int	i, j;
	size_t	counter;
	if(!vec)
		return (0);
	i = 0;
	counter = 0;
	*first = 5;
	*last = 0;
	while(i < 4 && vec[i])
	{
		j = 0;
		while(vec[i][j])
		{
			if(vec[i][j] == '#')
			{
				if(*first > j)
					*first = j;
				while(vec[i][j] == '#')
					j++;
				if(*last < j)
					*last = j;
				counter+=1;
			}
			else
				j++;
		}
		i++;
	}
	return counter;
}
