#include "fillit.h"

#define SUCCESS 1
#define FAILURE 0

#define OPTS 0
#define TETR 1

int		get_best_opts(t_node **m_lst)
{
	int		n_opt;
	int		n_of[2];
	int		mlst_h;
	int		tetr_n;

	update_mlst_status(m_lst, mlst_h, n_of);
	tetr_n = n_of[TETR];
	mlst_h = get_mlst_h(m_lst);
	n_opt = 0;
	while (n_opt < mlst_h)
	{
		choose_option(m_lst, n_opt);
		update_mlst_status(m_lst, mlst_h, n_of);
		if (n_of[TETR] == n_of[OPTS])
			return (SUCCESS);
		else
			unchoose_option(m_lst, n_opt);
		n_opt += 1;
	}
	return (FAILURE);
}

/* int		get_best_opts(t_node **m_lst) */
/* { */
/* 	int		n_of[2]; */
/* 	t_node	*cur; */
/* 	t_node	*last_cov; */
/* 	int		mlst_h; */
/* 	int		tetr_n; */

/* 	update_mlst_status(m_lst, mlst_h, n_of); */
/* 	tetr_n = n_of[TETR]; */
/* 	mlst_h = get_mlst_h(m_lst); */
/* 	cur = m_lst[1]; */
/* 	while (cur->role != 'z') */
/* 	{ */
/* 		cur = cur->d; */
/* 		if (cur->role == 'h') */
/* 		{ */
/* 			cur = cur->r; */
/* 			continue ; */
/* 		} */
/* 		choose_option(m_lst, cur->x); */
/* 		update_mlst_status(m_lst, mlst_h, n_of); */
/* 		if (n_of[TETR] == n_of[OPTS]) */
/* 			return (SUCCESS); */
/* 		else if (n_of[OPTS] < n_of[TETR]) */
/* 		{ */
/* 			cur = unchoose_option(m_lst, cur->x); */
/* 			continue ; */
/* 		} */
/* 		cur = cur->s->r; */
/* 	} */
/* 	return (FAILURE); */
/* } */
