/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_tetr_mlst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:43:21 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:43:27 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_num_of_tetr_mlst(t_node **m_lst)
{
	int		num;
	char		prev;
	int		i;

	i = num = 0;
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

int	get_num_of_tetr_mlst_conseq(t_node **m_lst)
{
	int	num;
	char	prev;
	int	found_new_char;
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
			while (cur->role != 'h')
			{
				if (cur->role == 'b')
				{
					if (cur->c == prev + 1)
					{
						prev = cur->c;
						found_new_char = 1;
						num += 1;
					}
				}
				cur = cur->d;
			}
			cur = cur->r;
		}
	}
	return (num);
}
