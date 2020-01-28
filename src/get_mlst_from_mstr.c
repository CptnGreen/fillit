/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlst_from_mstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:29:53 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:53:07 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		translate_upper_row(t_node **m_lst, size_t w)
{
	int			i;
	size_t		n;

	m_lst[0] = get_new_node(0, 'z', -1, -1);
	m_lst[0]->c = 'Z';
	i = 1;
	while (i < (w + 1))
	{
		m_lst[i] = get_new_node(i, 'h', -1, i - 1);
		m_lst[i]->c = 'H';
		m_lst[i - 1]->r = m_lst[i];
		m_lst[i]->l = m_lst[i - 1];
		i++;
	}
	m_lst[i - 1]->r = m_lst[0];
	m_lst[0]->l = m_lst[i - 1];
}

t_node		**get_mlst_from_mstr(char **m_str)
{
	t_node	**m_lst;
	size_t	h;
	size_t	w;
	size_t	n;

	w = get_mstr_w(m_str);
	h = get_mstr_h(m_str);
	n = get_num_of_blocks_in_mstr(m_str);
	m_lst = (t_node **)malloc((h + w + n + 3) * sizeof(t_node *));
	translate_upper_row(m_lst, w);
	translate_blocks_and_spacers(m_lst, m_str, w, n);
	create_vert_connections_in_mlst(m_lst);
	return (m_lst);
}
