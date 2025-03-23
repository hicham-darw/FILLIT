#include "fillit.h"

char	**initial_table(size_t size)
{
	size_t	i;
	char	**table;
	
	table = (char **)ft_memalloc(sizeof(char*) * (size + 1));
	if (!table)
		return NULL;
	i = 0;
	while(i < size)
	{
		table[i] = ft_strnew(sizeof(char) * size);
		if(!table[i])
			return NULL;
		ft_memset(table[i], '.', size);
		i++;
	}
	table[i] = NULL;
	return table;
}
