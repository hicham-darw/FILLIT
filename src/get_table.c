#include "fillit.h"

int	get_table(char ***ptr, int count_ptr, int len_ptr, char **table, int size_table)
{
	int	i, j;
	
	if(ptr[count_ptr] == NULL)
		return 1;
	i = 0;
	while(i < size_table)
	{
		j = 0;
		while(j < size_table)
		{
			if(clean_place(ptr[count_ptr], table, i, j))
			{
				fill_table(ptr[count_ptr], count_ptr, table, i, j);
				if(get_table(ptr, count_ptr+1,len_ptr,table, size_table))
					return 1;
				remove_tetriminos(table, count_ptr);
			}
			j++;
		}
		i++;
	}
	return 0;
}
