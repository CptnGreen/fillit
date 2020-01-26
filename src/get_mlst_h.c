#include "fillit.h"

int		get_mlst_h(t_node **m_lst)
{
    int		num_of_s;
	t_node	*cur;

	cur = m_lst[0];
	cur = (m_lst[0]->role == 'z') ? (cur->d) : (cur);
	num_of_s = 0;
	while (cur->c != '$')
	{
		num_of_s += 1;
		cur = cur->d;
	}
    return (num_of_s);
}
