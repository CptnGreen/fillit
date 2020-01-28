/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uncover_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:42:26 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 03:42:36 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	uncover_item(t_node **m_lst, t_node *hdr)
{
	t_node	*cur;
	int		n_item;

	cur = hdr;
	if (cur->c == 'h')
	{
		insert_node(cur);
		cur->c = 'H';
		cur = cur->s;
		while (cur->role != 'h')
		{
			uncover_option_of_node(m_lst, cur);
			cur = cur->s;
		}
	}
}
