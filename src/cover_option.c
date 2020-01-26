#include "fillit.h"

void	cover_option(t_node **m_lst, int n_opt)
{
	int		i;
	int		j;
	t_node	*cur;

	cur = m_lst[0];
	while (cur->x != n_opt)
		cur = cur->d;
	if (ft_islower(cur->c))
		return ;
	cur->c = ft_tolower(cur->c);
	/* delete_node(cur); */
	i = (m_lst[0]->role == 'z') ? (cur->n) : (cur->n - m_lst[0]->n);
	j = 0;
	while (j < 4)
	{
		cur = m_lst[i + 1 + j];
		delete_node(cur);
		j += 1;
	}
}
