#include "fillit.h"

void	choose_option(t_node **m_lst, int n_opt)
{
	t_node	*cur;
	int		i;
	int		j;

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
			cover_item(m_lst, m_lst[i + 1 + j]->y);
			j += 1;
		}
	}
}
