#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"

#define BUFF_SIZE 300

int	check_hash(char *str);
int	check_valid_tetris(char **vec);
int	clean_place(char **ptr, char **table, int rows, int cols);
int	count_hash(char **vec, int start, int last);
char	***cut_tetris(char **vec);
char	**fill_table(char **tetriminos, int count_ptr, char **table, int row, int col);
int	get_table(char ***ptr, int count_ptr, int len_ptr, char **table, int size_table);
char	**initial_table(size_t size_table);
size_t	len_tetris_and_str(char **vec, int *first, int *last);
char	**remove_tetriminos(char **table, int count_ptr);
int	check_ptr(char ***ptr);
int	veclen_of_vec(char ***ptr);

#endif
