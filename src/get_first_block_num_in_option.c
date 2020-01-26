#include "fillit.h"

int		get_first_block_num_in_option(t_node **m_lst, int n_opt)
{
	int		found_node;
	t_node	*cur;
	int		i;

	i = 0;
	found_node = 0;
	cur = m_lst[0]->s->r;
	while (cur->role != 'z')
	{
		cur = cur->d;
		if (cur->role == 'h')
		{
			cur = cur->r;
			continue ;
		}
		if (cur->x == n_opt)
		{
			found_node = 1;
			while (m_lst[i] && m_lst[i] != cur)
				i += 1;
			break ;
		}
	}
	/* printf("get_first_block: n_opt = %d, i = %d\n", n_opt, i); */
	return ((found_node) ? (i) : (-1));
}

/* int		get_first_block_num_in_option(t_node **m_lst, int n_opt) */
/* { */
/* 	int		i; */
/* 	int		found_node; */

/* 	found_node = 0; */
/* 	i = 0; */
/* 	while (m_lst[i] && n_opt - m_lst[i]->x >= 0) */
/* 	{ */
/* 		if (m_lst[i]->role == 'b' && m_lst[i]->x == n_opt) */
/* 		{ */
/* 			found_node = 1; */
/* 			break ; */
/* 		} */
/* 		i += 1; */
/* 	} */
/* 	return ((found_node) ? (i) : (-1)); */
/* } */
