#include "fillit.h"

void	cover_item(t_node **m_lst, t_node *hdr)
{
	t_node	*cur;
	t_node	*tmp;
	int		n_item;

	cur = hdr;
	if (cur->c == 'H')
	{
		cur->s = cur->u;
		tmp = cur;
		cur = cur->d;
		while (cur->x > cur->u->x)
		{
			cur->s = tmp;
			tmp = cur;
			cover_option_of_node(m_lst, cur);
			cur = cur->d;
		}
		cur->s = tmp;
		delete_node(cur);
		cur->c = 'h';
	}
}
