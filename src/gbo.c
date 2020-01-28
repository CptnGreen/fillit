/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:57:48 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:57:52 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		gbo(t_node **m_lst)
{
	int		i;
	int		n_of[4];
	t_node	**mlst_new;
	int		is_first;

	if (m_lst)
	{
		i = 0;
		is_first = 1;
		while (1)
		{
			if (is_first && m_lst[0]->role != 'z')
				i = 0;
			else if (skip_to_next_unempty_opt(m_lst, &i) == 0)
				break ;
			is_first = 0;
			choose_option(m_lst, m_lst[i]->x);
			update_mlst_status(m_lst, n_of);
			if (n_of[CHOS] == n_of[TETR_ALL])
				return (SUCCESS);
			mlst_new = get_next_submatrix_ptr(m_lst, i);
			if (n_of[TETR_PRES] + n_of[CHOS] < n_of[TETR_ALL] || !mlst_new)
			{
				unchoose_option(m_lst, m_lst[i]->x);
				continue ;
			}
			if (gbo(mlst_new) == SUCCESS)
				return (SUCCESS);
			unchoose_option(m_lst, m_lst[i]->x);
		}
	}
	return (FAILURE);
}
