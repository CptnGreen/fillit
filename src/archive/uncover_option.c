#include "fillit.h"

int		uncover_option(t_node **m_lst, int n_opt)
{
	int		i;
	int		found_block;

	found_block = 0;

	i = 0;
	while (!(m_lst[i + 1]->role == 's' && m_lst[i]->x == n_opt))
		i += 1;
	while (m_lst[i]->role != 's')
	{
		include_node(m_lst[i]);
		found_block = 1;
		i -= 1;
	}
	return (found_block);
}

/* int		uncover_option_conseq(t_node **m_lst, t_node *tmp) */
/* { */
/* 	int		row; */
/* 	t_node	*cur; */
/* 	int		found_block; */

/* 	found_block = 0; */
/* 	row = tmp->x; */
/* 	cur = m_lst[0]; */
/* 	cur = cur->l; */
/* 	while (cur->role != 'z') */
/* 	{ */
/* 		cur = cur->u; */
/* 		while (cur->role != 'h') */
/* 		{ */
/* 			if (cur->x == row) */
/* 			{ */
/* 				include_node(cur); */
/* 				found_block = 1; */
/* 			} */
/* 			cur = cur->u; */
/* 		} */
/* 		cur = cur->l; */
/* 	} */
/* 	return (found_block); */
/* } */
