#include "fillit.h"

void	toggle_spacer(t_node **m_lst, t_node *cur)
{
	int		i;

	i = 0;
	while (m_lst[i] != cur)
		i += 1;
	while (m_lst[i]->role != 's')
		i -= 1;
	if (m_lst[i]->c == 's')
		m_lst[i]->c = 'S';
	else if (m_lst[i]->c == 'S')
		m_lst[i]->c = 's';
}
