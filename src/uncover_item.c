#include "fillit.h"

void	uncover_item(t_node **m_lst, int n_item)
{
	t_node	*cur;

	/* printf("After uncovering item #%d\n", n_item); */
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
	/* print_matrix_lst_conseq(m_lst); */
}
