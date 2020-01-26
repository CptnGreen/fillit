#include "fillit.h"

t_node	*cover_item(t_node **m_lst, t_node *tmp)
{
	t_node	*last_excl;

	last_excl = NULL;
    tmp = tmp->d;
    while (tmp->role != 'h')
    {
		last_excl = cover_option(m_lst, tmp->x);
		tmp = tmp->d;
	}
	return (last_excl);
}
