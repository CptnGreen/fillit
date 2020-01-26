#include "fillit.h"

void	cover_item(t_node **m_lst, int n_item)
{
	t_node	*cur;
	t_node	*tmp;

	/* printf("After covering item #%d:\n", n_item); */
	cur = m_lst[0]->s;
	while (cur->y != n_item)
		cur = cur->r;
	if (cur->c == 'H')
	{
		cur->s = cur->u;
		tmp = cur;
		cur = cur->d;
		while (cur->x > cur->u->x)
		{
			cur->s = tmp;
			tmp = cur;
			cover_option(m_lst, cur->x);
			cur = cur->d;
		}
		cur->s = tmp;
		delete_node(cur);
		cur->c = 'h';
	}
	/* print_matrix_lst_conseq(m_lst); */
}
