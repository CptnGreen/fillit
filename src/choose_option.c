#include "fillit.h"

void	choose_option(t_node **m_lst, int n_opt)
{
	t_node	*cur;
	int		i;
	int		j;

	printf("After choosing option #%d:\n", n_opt);
	cur = m_lst[0]->s;
	while (cur->x != n_opt)
		cur = cur->d;
	if (cur->c != '*' && ft_isupper(cur->c))
	{
		cur->c = '*';
		i = (m_lst[0]->role == 'z') ? (cur->n) : (cur->n - m_lst[0]->n);
		j = 0;
		while (j < 4)
		{
			/* cover_item_except_one_opt(m_lst, m_lst[i + 1 + j]->y, n_opt); */
			cover_item(m_lst, m_lst[i + 1 + j]->y);
			j += 1;
		}
	}
	print_matrix_lst_conseq(m_lst);
}
