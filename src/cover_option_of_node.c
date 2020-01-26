#include "fillit.h"

void	cover_option_of_node(t_node **m_lst, t_node *node)
{
	int		i;
	int		j;
	t_node	*cur;

	cur = node->l;
	if (ft_islower(cur->c))
		return ;
	cur->c = ft_tolower(cur->c);
	i = (m_lst[0]->role == 'z') ? (cur->n) : (cur->n - m_lst[0]->n);
	j = 0;
	while (j < 4)
	{
		cur = m_lst[i + 1 + j];
		delete_node(cur);
		j += 1;
	}
}
