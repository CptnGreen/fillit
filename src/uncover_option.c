#include "fillit.h"

void	uncover_option(t_node **m_lst, int n_opt)
{
	int		i;
	t_node	*cur;

	/* printf("Uncovering option #%d\n", n_opt); */
	cur = m_lst[0];
	while (cur->x != n_opt)
		cur = cur->d;
	if (ft_islower(cur->c) || cur->c == '*')
	{
		cur->c = ft_toupper(cur->r->c);
		cur = cur->d->l;
		i = (m_lst[0]->role == 'z') ? (cur->n) : (cur->n - m_lst[0]->n);
		while (m_lst[i]->role != 's')
		{
			insert_node(m_lst[i]);
			i -= 1;
		}
	}
	/* print_matrix_lst_conseq(m_lst); */
}
