#include "fillit.h"

int	count_hash(char **vec,int start, int last)
{
	int	counter, i;

	if (!vec)
		return 0;
	
	counter = 0;
	while(start < last && vec[start])
	{
		i = 0;
		while(vec[start][i])
		{
			if(vec[start][i] == '#')
				counter += 1;
			i++;
		}
		start++;
	}
	return counter;
}
