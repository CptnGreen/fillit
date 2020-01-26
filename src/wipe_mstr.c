#include "fillit.h"

void	wipe_mstr(char **m)
{
	int		i;

	i = 0;
	while (m[i])
	{
		ft_strdel(m + i);
		i++;
	}
	free(m);
	m = NULL;
}
