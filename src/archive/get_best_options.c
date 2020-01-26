#include "fillit.h"

#define SUCCESS 1
#define FAILURE 0

/*
** Description:
*/

int	get_best_options(t_node **m_lst)
{
	int			max_n_of_opts;
	int			cur_n_of_opts;
	int			max_n_of_tetr;
	int			cur_n_of_tetr;
	t_node		*cur;
	t_node		*last_excl;

	max_n_of_opts = get_num_of_tetr_mlst(m_lst);
	cur = m_lst[1];
	while (cur->role != 'z')
	{
		cur = cur->d;
		if (cur->role == 'h')
		{
			cur = cur->r;
			continue ;
		}
		else
		{
			last_excl = choose_option(m_lst, cur->x);
			cur_n_of_opts = get_n_of_opts_in_mlst(m_lst);
			cur_n_of_tetr = get_num_of_tetr_mlst(m_lst);
			if (cur_n_of_opts == max_n_of_opts && cur_n_of_tetr == max_n_of_tetr)
				return (SUCCESS);
			else if (cur_n_of_opts < max_n_of_opts)
			{
				unchoose_option(m_lst, last_excl->n);
				continue ;
			}
		}
	}
	return (FAILURE);
}
