#include "fillit.h"

int	count_hash(char **vec)
{
	int	counter, i, j;

	if (!vec)
		return 0;
	counter = 0;
	i = 0;
	while(vec[i])
	{
		j = 0;
		while(vec[i][j])
		{
			if(vec[i][j] == '.')
				j++;
			else if (vec[i][j] == '#')
			{
				counter++;
				j++;
			}
			else
				return 0;
		}
		i++;
	}
	return counter;
}
