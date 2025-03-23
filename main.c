#include "fillit.h"

int	main(int ac, char **av)
{
	int	fd, i, len_vector;
	int	read_size, size_table;
	char	buff[BUFF_SIZE];
	char	**vec, ***ptr, **table;
	

	if (ac != 2)
	{
		write(2, "usage: ./main valid_example.fillit\n", 35);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "ERROR: can't opened file", 24);
		return (-1);
	}
	ft_memset(buff, '0', BUFF_SIZE);
	buff[BUFF_SIZE] = '\0';
	while((read_size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		vec = ft_split_whitespaces(buff);
		if(!vec)
			return (-1);
		ptr = cut_tetris(vec);
		// free vector vec-------------------
		ft_del_vector(vec);
		if(!vec)
			write(1, "free vec\n", 9);
		if (check_valid_tetris(ptr) == 0)
		{
			write(2, "ERROR: invalide example\n", 24);
			return (-1);
		}
		// here open your mind and think how work fill it hahahha;
		size_table = 4;
		table = initial_table((size_t)size_table);
		len_vector = veclen_of_vec(ptr);
		//loop for resize +1 in one time;
		while(!get_table(ptr, 0, len_vector,table, size_table))
		{
			ft_del_vector(table);
			size_table += 1;
			table = initial_table(size_table);
			if(get_table(ptr, 0, len_vector, table, size_table) == 1)
				break;
		}
		ft_print_words_tables(table);
	}
	ft_memset(buff, '0', BUFF_SIZE);
	ft_del_vector(table);
	i = 0;
	while(i < veclen_of_vec(ptr))
	{
		ft_del_vector(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return 0;
}


