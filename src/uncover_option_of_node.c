/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uncover_option_of_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:03:16 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:03:21 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	uncover_option_of_node(t_node **m_lst, t_node *node)
{
	int		i;
	t_node	*cur;

	cur = node->l;
	if (ft_islower(cur->c) || cur->c == '*')
	{
		cur->c = ft_toupper(cur->r->c);
		cur = cur->d->l;
		i = (m_lst[0]->role == 'z') ? (cur->n) : (cur->n - m_lst[0]->n);
		while (m_lst[i]->role != 's')
		{
			insert_node(m_lst[i]);
			i -= 1;
		}
	}
}
