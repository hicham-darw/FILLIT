#include "fillit.h"

char	***cut_tetris(char **vec)
{
	size_t len, i, j, first , last, len_vec, count_vec, b;
	char	***ptr;
	if(!vec)
		return NULL;
	len = ft_veclen(vec); //length of vector for alloc ptr;
	ptr = (char***)ft_memalloc(sizeof(char **) * ((len / 4) + 1));
	if(!ptr)
		return NULL;
	len = len / 4;
	ptr[len] = NULL;
	i = 0;
	count_vec = 0;
	first = 5;
	last = 0;
	while(i < len && vec[count_vec])
	{
		//count len vector and resize strings for '#'
		len_vec = len_tetris_and_str((vec + count_vec),(int*)&first, (int*)&last);
		ptr[i] = (char**)malloc(sizeof(char*) * (len_vec + 1));
		if(!ptr[i])
			return NULL;
		ptr[i][len_vec] = NULL;
		b = 0;
		j = count_vec + 4; // j for next tetris
		while(b < len_vec)
		{
			if(check_hash(vec[count_vec]) == 1)
			{
				while(check_hash(vec[count_vec]) == 1 && b < len_vec)
				{
					ptr[i][b] = (char*)malloc(sizeof(char) * ((last - first) + 1));
					if(!ptr[i][b])
						return NULL;
					ft_strncpy(ptr[i][b], (vec[count_vec])+first, (last-first));
					count_vec++;
					b++;
				}
			}
			else
				count_vec++;
		}
		while(count_vec < j) //if stop in the middle tetris look j up;
			count_vec++;
		first = 5;
		last = 0;
		i++;
	}
	return ptr;
}
