#include "fillit.h"

void	unchoose_option(t_node **m_lst, int n_opt)
{
	t_node	*cur;
	int		i;

	printf("After unchoosing option #%d:\n", n_opt);
	cur = m_lst[0]->s;
	while (cur->x != n_opt)
		cur = cur->d;
	if (cur->c == '*')
	{
		cur = cur->d->l;
		/* cur->l->c = ft_toupper(cur->l->r->c); */
		i = (m_lst[0]->role == 'z') ? (cur->n) : (cur->n - m_lst[0]->n);
		while (m_lst[i]->role != 's')
		{
			/* print_node_info(m_lst[i]); */
			/* m_lst[i]->c = (m_lst[i]->r)->c; */
			uncover_item(m_lst, m_lst[i]->y);
			i -= 1;
		}
		m_lst[i]->c = m_lst[i]->r->c;
	}
	print_matrix_lst_conseq(m_lst);
}
