#include "fillit.h"

t_node		*cover_option(t_node **m_lst, int n_opt)
{
	t_node	*cur;
	t_node	*last_excl;

	last_excl = NULL;
	found_block = 0;
	cur = m_lst[1];
	while (cur->role != 'z')
	{
		cur = cur->d;
		if (cur->role == 'h')
		{
			cur = cur->r;
			continue ;
		}
		else if (cur->x == n_opt)
			last_excl = exclude_node(cur);
	}
	return (last_excl);
}
