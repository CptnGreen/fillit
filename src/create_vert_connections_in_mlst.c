/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vert_connections_in_mlst.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:33:30 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:56:57 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		connect_column(t_node **m_lst, int item, int n)
{
	int			i;
	t_node		*prev;

	prev = m_lst[n]->d;
	i = prev->n;
	while (m_lst[++i])
	{
		if (m_lst[i]->y == item)
		{
			connect_nodes_vert(m_lst[i], prev);
			prev = m_lst[i];
		}
	}
	connect_nodes_vert(m_lst[n], prev);
}

void		connect_headers_to_first_nodes(t_node **m_lst)
{
	int			n;
	int			item;
	int			i;

	n = 1;
	item = 0;
	while (m_lst[n]->role == 'h')
	{
		i = n + 1;
		while (m_lst[i])
		{
			if (m_lst[i]->y == item)
			{
				connect_nodes_vert(m_lst[i], m_lst[n]);
				break ;
			}
			i += 1;
		}
		n += 1;
		item += 1;
	}
}

void		connect_block_nodes_vertically(t_node **m_lst)
{
	int			n;
	int			item;
	t_node		*cur;

	n = 1;
	item = 0;
	while (m_lst[n]->role == 'h')
	{
		if (m_lst[n]->d)
			connect_column(m_lst, item, n);
		else
			connect_nodes_vert(m_lst[n], m_lst[n]);
		n++;
		item += 1;
	}
}

void		make_super_connections(t_node **m_lst)
{
	int		i;
	t_node	*cur;

	i = 0;
	while (m_lst[i])
	{
		if (m_lst[i]->role == 'b' || m_lst[i]->role == 'h')
			m_lst[i]->s = m_lst[i]->u;
		else if (m_lst[i]->role == 'z' || m_lst[i]->role == 's')
			m_lst[i]->s = m_lst[m_lst[i]->y + 1];
		i += 1;
	}
	cur = m_lst[0]->r;
	while (cur->role != 'z')
	{
		cur->s = cur->u;
		cur = cur->r;
	}
}

void		create_vert_connections_in_mlst(t_node **m_lst)
{
	connect_headers_to_first_nodes(m_lst);
	connect_block_nodes_vertically(m_lst);
	make_super_connections(m_lst);
}
