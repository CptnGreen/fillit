/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlst_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:41:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:42:02 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_mlst_w(t_node **m_lst)
{
	int		w;
	t_node	*cur;

	w = 0;
	cur = m_lst[0]->s->r;
	while (cur->role == 'h')
	{
		w++;
		cur = cur->r;
	}
	return (w);
}
