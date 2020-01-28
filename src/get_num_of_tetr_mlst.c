/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_tetr_mlst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:42:43 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:42:47 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_num_of_tetr_mlst(t_node **m_lst)
{
	int		num;
	char	prev;
	int		i;

	num = 0;
	i = 0;
	prev = '0';
	while (m_lst[i])
	{
		if (m_lst[i]->role == 'b' && m_lst[i]->c != prev)
		{
			prev = m_lst[i]->c;
			num++;
		}
		i++;
	}
	return (num);
}

void	get_num__handle_item(\
	t_node **cur, char *prev, int *num, int *found_new_char)
{
	while ((*cur)->role != 'h')
	{
		if ((*cur)->role == 'b' && (*cur)->c == (*prev) + 1)
		{
			(*prev) = (*cur)->c;
			(*found_new_char) = 1;
			(*num) += 1;
		}
		(*cur) = (*cur)->d;
	}
}

int		get_num_of_tetr_mlst_conseq(t_node **m_lst)
{
	int		num;
	char	prev;
	int		found_new_char;
	t_node	*cur;

	num = 0;
	cur = m_lst[1];
	prev = 'A' - 1;
	found_new_char = 1;
	while (found_new_char)
	{
		found_new_char = 0;
		while (cur->role == 'h')
		{
			cur = cur->d;
			get_num__handle_item(&cur, &prev, &num, &found_new_char);
			cur = cur->r;
		}
	}
	return (num);
}
