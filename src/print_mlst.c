#include "fillit.h"

void    print_mlst(t_node **m_lst)
{
    int			w;
    int			h;
    int			x0;
    char		**m;
    t_node		*cur;

    h = get_mlst_h(m_lst);
    w = get_mlst_w(m_lst);
    m = get_matrix_of_dots(h, w);
	cur = ((m_lst[0]->role == 'z') ? (m_lst[1]) : (m_lst[0]->s->r));
	x0 = ((m_lst[0]->role == 'z') ? (0) : (m_lst[0]->x));
	while (cur->role != 'z')
	{
		cur = cur->d;
		if (cur->role == 'h')
		{
			cur = cur->r;
			continue ;
		}
		if (cur->x >= x0)
		{
			m[cur->x - x0][cur->y] = cur->c;
			if (ft_islower(cur->c))
				print_node_info(cur);
		}
	}
	print_mstr(m);
}
