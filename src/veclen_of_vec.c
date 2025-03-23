#include "fillit.h"

int	veclen_of_vec(char ***ptr)
{
	int	i;

	if(!ptr)
		return 0;
	i = 0;
	while(ptr[i])
		i++;
	return i;
}
