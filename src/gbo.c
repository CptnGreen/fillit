/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:57:48 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 04:42:47 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** gbo = get best options
**
** n_of[TA] - full number of encoded tetriminoes (covered and uncovered)
** n_of[TU] - number of uncovered (visible) tetrs
** n_of[CH] - number of chosen options (spacers are *)
*/

int		gbo(t_node **m_lst, int *n_of)
{
	int		i;
	t_node	**ptr;
	int		is_first;

	i = 0;
	is_first = 1;
	while (m_lst)
	{
		if (!(is_first && m_lst[0]->role != 'z') && skip(m_lst, &i) == 0)
			break ;
		is_first = 0;
		choose_option(m_lst, m_lst[i]->x);
		update_mlst_status(m_lst, n_of);
		if (n_of[CH] == n_of[TA])
			return (SUCCESS);
		if (n_of[TU] + n_of[CH] < n_of[TA] || !(ptr = get_ptr(m_lst, i)))
		{
			unchoose_option(m_lst, m_lst[i]->x);
			continue ;
		}
		if (gbo(ptr, n_of) == SUCCESS)
			return (SUCCESS);
		unchoose_option(m_lst, m_lst[i]->x);
	}
	return (FAILURE);
}
