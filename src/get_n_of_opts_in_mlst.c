/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_of_opts_in_mlst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:42:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:42:43 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_n_of_opts_in_mlst(t_node **m_lst)
{
	int		n;
	int		i;

	n = 0;
	i = 1;
	while (m_lst[i]->role != 'b')
		i += 1;
	while (m_lst[i])
	{
		if (m_lst[i]->role == 'b')
		{
			n += 1;
			while (m_lst[i]->role != 's')
				i += 1;
		}
		i += 1;
	}
	return (n);
}
