#include "fillit.h"

int	check_ptr(char ***ptr)
{
	int	i;

	if(!ptr)
		return 0;
	i = 0;
	while(ptr[i])
	{
		if(ft_strlen(ptr[i][0]) == 4)
		{
			if(ft_veclen(ptr[i]) != 1)
				return 0;
		}
		else if(ft_strlen(ptr[i][0]) == 3)
		{
			if(ft_veclen(ptr[i]) != 2)
				return 0;
		}
		else if(ft_strlen(ptr[i][0]) == 2)
		{
			if(ft_veclen(ptr[i]) > 3)
				return 0;
		}
		else
		{
			if(ft_veclen(ptr[i]) != 4)
				return 0;
		}
		i++;
	}
	return 1;
}
