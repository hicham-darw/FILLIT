#include "fillit.h"

int	clean_place(char **ptr, char **table, int rows, int cols)
{
	int	tmp_rows, tmp_cols, rows_ptr, cols_ptr;
	
	if(!ptr || !table)
		return 0;
	
	if(((int)ft_veclen(table) - rows) < ((int)ft_veclen(ptr)))
		return 0;
	
	else if (((int)(ft_strlen(table[rows])) - cols) < ((int)ft_strlen(ptr[0])))
		return 0;
	else
	{
		tmp_rows = rows;
		rows_ptr = 0;
		while(ptr[rows_ptr])
		{
			tmp_cols = cols;
			cols_ptr = 0;
			while(ptr[rows_ptr][cols_ptr])
			{
				if(ptr[rows_ptr][cols_ptr] == '#')
				{
					if(ft_isalpha(table[tmp_rows][tmp_cols]) == 1)
						return 0;
					else
					{
						tmp_cols++;
						cols_ptr++;
					}
				}
				else
				{
					tmp_cols++;
					cols_ptr++;
				}
			}
			rows_ptr++;
			tmp_rows++;
		}
	}
	return 1;
}
