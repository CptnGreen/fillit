/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlst_from_mstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:29:53 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 21:47:35 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		translate_upper_row(t_node **m_lst, size_t w)
{
	int			i;
	size_t		n;

	m_lst[0] = get_new_node(0, 'z', 'Z', -1, -1);
	i = 1;
	while (i < (w + 1))
	{
		m_lst[i] = get_new_node(\
			i, 'h', 'H', -1, i - 1);
		m_lst[i - 1]->r = m_lst[i];
		m_lst[i]->l = m_lst[i - 1];
		i++;
	}
	m_lst[i - 1]->r = m_lst[0];
	m_lst[0]->l = m_lst[i - 1];
}

void		translate_last_node(t_node **m_lst, int i)
{
	m_lst[i] = NULL;
	m_lst[i - 1]->d = m_lst[0];
	m_lst[0]->u = m_lst[i - 1];
	m_lst[i - 1]->c = '$';
}

void		translate_blocks_and_spacers(\
				t_node **m_lst, char **m_str, size_t w, \
				size_t h, size_t n)
{
	int			i;
	int			x;
	int			y;
	t_node		*spacer;
	int			j;

	i = w + 1;
	x = 0;
	y = -1;
	m_lst[i] = get_new_node(i, 's', 's', 0, -1);
	spacer = m_lst[i];
	spacer->u = m_lst[0];
	m_lst[0]->d = spacer;
	i++;
	while (i < (h + w + n + 2))
	{
		y++;
		if (m_str[x][y] >= 'A' && m_str[x][y] <= 'Z')
		{
			m_lst[i] = get_new_node(i, 'b', m_str[x][y], x, y);
			m_lst[i]->l = spacer;
			if (spacer->r == NULL)
				spacer->r = m_lst[i];
			spacer->c = m_str[x][y];
			i++;
		}
		else if (m_str[x][y] == '\0')
		{
			m_lst[i] = get_new_node(i, 's', 's', x + 1, -1);
			m_lst[i]->u = spacer;
			spacer->d = m_lst[i];
			spacer = m_lst[i];
			j = 0;
			while (j < 4)
				m_lst[i - 1 - j++]->r = spacer;
			spacer->l = m_lst[i - 1];
			i++;
			x++;
			y = -1;
		}
	}
	translate_last_node(m_lst, i);
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
	translate_blocks_and_spacers(m_lst, m_str, w, h, n);
	create_vert_connections_in_mlst(m_lst);
	return (m_lst);
}
