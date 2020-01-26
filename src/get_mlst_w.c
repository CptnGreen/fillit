#include "fillit.h"

int		get_mlst_w(t_node **m_lst)
{
    int		w;
	t_node	*cur;

	w = 0;
	cur = m_lst[0]->s->r;
	while (cur->role == 'h')
	{
		w++;
		cur = cur->r;
	}
	return (w);
}
