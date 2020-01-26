#include "fillit.h"

int		uncover_item(t_node **m_lst, t_node *tmp)
{
	int		n_of_incl_opts;
	int		i;
	int		col;

	col = tmp->y;
	n_of_incl_opts = 0;
	i = 1;
	while (m_lst[i])
		i += 1;
	i -= 1;
	while (m_lst[i] != tmp)
	{
		if (m_lst[i]->role == 'b' && m_lst[i]->y == col)
		{
			if (uncover_option(m_lst, m_lst[i]->x))
				n_of_incl_opts += 1;
		}
		i -= 1;
	}
	return (n_of_incl_opts);
}


/* int		uncover_item_conseq(t_node **m_lst, t_node *tmp) */
/* { */
/* 	int		n_of_incl_opts; */
/* 	t_node	*cur; */

/* 	n_of_incl_opts = 0; */
/* 	cur = tmp; */
/* 	while (cur->role != 'h') */
/* 		cur = cur->d; */
/* 	cur = cur->u; */
/* 	while (cur != tmp) */
/* 	{ */
/* 		if (uncover_option(m_lst, cur)) */
/* 			n_of_incl_opts += 1; */
/* 		cur = cur->u; */
/* 	} */
/* 	return (n_of_incl_opts); */
/* } */
