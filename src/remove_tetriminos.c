#include "fillit.h"

char	**remove_tetriminos(char **table, int count_ptr)
{
	int	i, j;
	
	if(!table)
		return NULL;
	i = 0;
	while(table[i])
	{
		j = 0;
		while(table[i][j])
		{
			if(table[i][j] == count_ptr + 'A')
				table[i][j] = '.';
			j++;
		}
		i++;
	}
	return table;
}
