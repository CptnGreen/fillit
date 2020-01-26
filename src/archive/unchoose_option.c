#include "fillit.h"

int		unchoose_option(t_node **m_lst, int n_opt)
{
	char	letter;
	int		i;
	int		n_of_incl_opts;

	n_of_incl_opts = 0;
	i = 0;
	while (!(m_lst[i]->role == 'b' && m_lst[i]->x != n_opt))
		i += 1;
	letter = m_lst[i]->c;
	while (m_lst[i]->role != 's')
	{
		n_of_incl_opts += uncover_item(m_lst, m_lst[i]);
		i -= 1;
	}
	n_of_incl_opts += \
		include_letter_occurences_except_row(m_lst, letter, n_opt);
	return (n_of_incl_opts);
}
