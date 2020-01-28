/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_blocks_and_spacers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:21:19 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:53:07 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		translate_first_spacer(t_node **m_lst, int *i, t_node **spacer)
{
	m_lst[*i] = get_new_node(*i, 's', 0, -1);
	m_lst[*i]->c = 'S';
	*spacer = m_lst[*i];
	(*spacer)->u = m_lst[0];
	m_lst[0]->d = *spacer;
	(*i) += 1;
}

void		translate_endl(t_node **m_lst, int *x, int *i, t_node **spacer)
{
	int		j;

	m_lst[*i] = get_new_node(*i, 's', *x + 1, -1);
	m_lst[*i]->c = 'S';
	m_lst[*i]->u = *spacer;
	(*spacer)->d = m_lst[*i];
	*spacer = m_lst[*i];
	j = 0;
	while (j < 4)
		m_lst[*i - 1 - j++]->r = *spacer;
	(*spacer)->l = m_lst[*i - 1];
	(*i) += 1;
	(*x) += 1;
}

void		translate_letter(t_node **m_lst, char letter, int *i, t_node **sp)
{
	m_lst[*i]->l = *sp;
	if ((*sp)->r == NULL)
		(*sp)->r = m_lst[*i];
	(*sp)->c = letter;
	(*i) += 1;
}

void		translate_last_node(t_node **m_lst, int i)
{
	m_lst[i] = NULL;
	m_lst[i - 1]->d = m_lst[0];
	m_lst[0]->u = m_lst[i - 1];
	m_lst[i - 1]->c = '$';
}

void		translate_blocks_and_spacers(\
				t_node **m_lst, char **m_str, size_t w, size_t n)
{
	int			i;
	int			x;
	int			y;
	t_node		*spacer;

	i = w + 1;
	x = 0;
	y = -1;
	translate_first_spacer(m_lst, &i, &spacer);
	while (i < (get_mstr_h(m_str) + w + n + 2))
	{
		y++;
		if (m_str[x][y] >= 'A' && m_str[x][y] <= 'Z')
		{
			m_lst[i] = get_new_node(i, 'b', x, y);
			m_lst[i]->c = m_str[x][y];
			translate_letter(m_lst, m_str[x][y], &i, &spacer);
		}
		else if (m_str[x][y] == '\0')
		{
			translate_endl(m_lst, &x, &i, &spacer);
			y = -1;
		}
	}
	translate_last_node(m_lst, i);
}
