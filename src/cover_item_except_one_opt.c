#include "fillit.h"

void	cover_item_except_one_opt(t_node **m_lst, int n_item, int n_opt)
{
	t_node	*cur;

	printf("After covering item #%d (except opt #%d):\n", n_item, n_opt);
	cur = m_lst[0]->s;
	while (cur->y != n_item)
		cur = cur->r;
	if (cur->c != 'h')
	{
		cur = cur->d;
		while (cur->role != 'h')
		{
			/* if (/\*cur->x >= m_lst[0]->x && *\/cur->x != n_opt) */
				cover_option(m_lst, cur->x);
			cur = cur->d;
		}
	}
	cur->c = 'h';
	/* print_node_info(cur); */
	print_matrix_lst_conseq(m_lst);
}
