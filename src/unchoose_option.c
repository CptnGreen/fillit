#include "fillit.h"

void	unchoose_option(t_node **m_lst, int n_opt)
{
	t_node	*cur;
	int		i;

	cur = m_lst[0]->s;
	while (cur->x != n_opt)
		cur = cur->d;
	if (cur->c == '*')
	{
		cur = cur->d->l;
		i = (m_lst[0]->role == 'z') ? (cur->n) : (cur->n - m_lst[0]->n);
		while (m_lst[i]->role != 's')
		{
			uncover_item(m_lst, m_lst[i]->y);
			i -= 1;
		}
		m_lst[i]->c = m_lst[i]->r->c;
	}
}
