#include "fillit.h"

char	**fill_table(char **tetriminos, int count_ptr, char **table, int row, int col)
{
	int	i, j, tmp_row, tmp_col;

	if(!tetriminos || !table)
		return NULL;
	tmp_row = row;
	i = 0;
	while((size_t)i < ft_veclen(tetriminos) && tetriminos[i] && table[tmp_row])
	{
		tmp_col = col;
		j = 0;
		while((size_t)j < ft_strlen(tetriminos[i]) && tetriminos[i][j])
		{
			if(tetriminos[i][j] == '#')
				table[tmp_row][tmp_col] = (unsigned char)count_ptr + 'A';
			tmp_col++;
			j++;
		}
		tmp_row++;
		i++;
	}
	return table;
}
