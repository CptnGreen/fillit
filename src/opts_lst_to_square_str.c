/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_lst_to_square_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:00:01 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 08:35:26 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_spacer(t_node **m_lst, t_node *cur)
{
	if (cur->l->c == '*')
		return (1);
	return (0);
}

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
			m_str[x][y] = ft_toupper(cur->c);
		}
		i += 1;
	}
	wipe_mlst(m_lst);
	return (m_str);
}
