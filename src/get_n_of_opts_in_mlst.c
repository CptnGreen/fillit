/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_of_opts_in_mlst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:54:19 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:54:23 by slisandr         ###   ########.fr       */
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
