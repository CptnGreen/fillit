#include "fillit.h"

int		check_spacer(t_node **m_lst, t_node *cur);

char	**opts_lst_to_square_str(t_node **m_lst, int sq_side)
{
	char	**m_str;
	t_node	*cur;
	int		x;
	int		y;
	int		i;

	m_str = get_matrix_of_dots(sq_side, sq_side);
	cur = m_lst[1];
	i = 0;
	while ((cur = m_lst[i]))
	{
		if (cur->role == 'b' && check_spacer(m_lst, cur))
		{
			x = cur->y / sq_side;
			y = cur->y % sq_side;
			m_str[x][y] = cur->c;
		}
		i += 1;
	}
	return (m_str);
}

int		check_spacer(t_node **m_lst, t_node *cur)
{
	if (cur->l->c == '*')
		return (1);
	return (0);
}
