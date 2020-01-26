#include "fillit.h"

int		skip_to_next_unempty_opt(t_node **m_lst, int *index)
{
	t_node	*cur;
	char	letter;

	letter = (m_lst[*index]->c == '*') ? \
		ft_toupper((m_lst[*index]->r->c)) : ft_toupper((m_lst[*index]->c));
	cur = (m_lst[0]->role == 'z') ? (m_lst[0]->d) : (m_lst[0]);
	while (cur->role != 'z')
	{
		if (cur->c == '$' || ft_toupper(cur->c) > letter)
			return (FAILURE);
		if (ft_isupper(cur->c) && cur->x > m_lst[*index]->x)
		{
			*index = cur->n - m_lst[0]->n;
			return (SUCCESS);
		}
		cur = cur->d;
	}

	return (FAILURE);
}
