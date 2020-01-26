#include "fillit.h"

void	uncover_item(t_node **m_lst, int n_item)
{
	t_node	*cur;

	cur = m_lst[0]->s;
	while (cur->y != n_item)
		cur = cur->r;
	if (cur->c == 'h')
	{
		insert_node(cur);
		cur->c = 'H';
		cur = cur->s;
		while (cur->role != 'h')
		{
			uncover_option(m_lst, cur->x);
			cur = cur->s;
		}
	}
}
