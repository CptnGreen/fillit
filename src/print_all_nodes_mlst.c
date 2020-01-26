#include "fillit.h"

void	print_all_nodes_mlst(t_node **m_lst)
{
	int		i;

	i = 0;
	while (m_lst[i])
	{
		print_node_info(m_lst[i]);
		i += 1;
	}
}
