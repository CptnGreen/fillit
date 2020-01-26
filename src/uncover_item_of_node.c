#include "fillit.h"

void	uncover_item_of_node(t_node **m_lst, t_node *hdr)
{
	t_node	*cur;
	int		n_item;

	cur = hdr;
	if (cur->c == 'h')
	{
		insert_node(cur);
		cur->c = 'H';
		cur = cur->s;
		while (cur->role != 'h')
		{
			uncover_option_of_node(m_lst, cur);
			cur = cur->s;
		}
	}
}
