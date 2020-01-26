#include "fillit.h"

int		get_last_block_num_in_option(t_node **m_lst, int n_opt)
{
	int		i;

	if ((i = get_first_block_num_in_option(m_lst, n_opt)) < 0)
		return (-1);
	while (m_lst[i]->role != 's')
		i += 1;
	i -= 1;
	return (i);
}
