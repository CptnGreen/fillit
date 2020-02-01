/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_mlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 07:54:16 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 11:27:41 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	wipe_node(t_node *node)
{
	node->u = NULL;
	node->r = NULL;
	node->d = NULL;
	node->l = NULL;
	node->s = NULL;
	free(node);
	node = NULL;
}

void	wipe_mlst(t_node **m_lst)
{
	int		i;

	i = 0;
	while (m_lst[i])
	{
		wipe_node(m_lst[i]);
		i += 1;
	}
	free(m_lst);
	m_lst = NULL;
}
