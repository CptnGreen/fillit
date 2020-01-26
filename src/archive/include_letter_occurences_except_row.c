#include "fillit.h"

int		include_letter_occurences_except_row(\
	t_node **m_lst, char letter, int row)
{
	int		i;
	int		n_of_incl_opts;

	n_of_incl_opts = 0;
	i = 0;
	while (m_lst[i + 1])
		i += 1;
	while (m_lst[i]->role != 'h')
	{
		if (m_lst[i]->role == 'b' && \
			m_lst[i]->c == letter && \
			m_lst[i]->x != row)
		{
		    if (uncover_option(m_lst, m_lst[i]->x))
				n_of_incl_opts += 1;
			while (m_lst[i]->role != 's')
				i -= 1;
		}
		i -= 1;
	}
	return (n_of_incl_opts);
}

/* int		include_letter_occurences_except_row_conseq(\ */
/* 	t_node **m_lst, char letter, int row) */
/* { */
/* 	int		n_of_incl_opts; */
/* 	t_node	*cur; */

/* 	n_of_incl_opts = 0; */
/* 	cur = m_lst[0]->l; */
/* 	while (cur->role != 'z') */
/* 	{ */
/* 		cur = cur->u; */
/* 		while (cur->role != 'h') */
/* 		{ */
/* 			if (cur->x != row && cur->c == letter) */
/* 			{ */
/* 				if (uncover_option(m_lst, cur)) */
/* 					n_of_incl_opts += 1; */
/* 			} */
/* 			cur = cur->u; */
/* 		} */
/* 		cur = cur->l; */
/* 	} */
/* 	printf("include_letters: incl opts = %d\n", n_of_incl_opts); */
/* 	return (n_of_incl_opts); */
/* } */
