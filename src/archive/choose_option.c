#include "fillit.h"

t_node		*get_first_node_of_opt(t_node **m_lst, int n_opt);

t_node		*choose_option(t_node **m_lst, int n_opt)
{
	char	letter;
	int		n_of_excl_opts;
	t_node	*cur;
	t_node	*last_excl;

	cur = get_first_node_of_opt(m_lst, n_opt);
	letter = cur->c;
	cur = m_lst[1];
	while (cur->role != 'z')
	{
		cur = cur->d;
		if (cur->role == 'h')
		{
			cur = cur->r;
			continue ;
		}
		else if (cur->c == letter)
			last_excl = cover_item(m_lst, cur);
	}
	return (last_excl);
}

t_node		*get_first_node_of_opt(t_node **m_lst, int n_opt)
{
	t_node	*cur;

	cur = m_lst[1];
	while (cur->role != 'z')
	{
		cur = cur->d;
		if (cur->role == 'h')
		{
			cur = cur->r;
			continue ;
		}
		else if (cur->x == n_opt)
			break ;
	}
	return (cur);
}
