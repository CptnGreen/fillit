/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:44:29 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 04:44:43 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Returns pointer to the beginning of the submatrix of opts with next letter
*/

t_node		**get_ptr(t_node **m_lst, int i)
{
	char	old_letter;
	t_node	*cur;
	int		n;

	cur = m_lst[i];
	old_letter = ft_toupper(cur->r->c);
	while (cur->c != '$' && cur->role != 'z')
	{
		if (cur->c != '*')
		{
			if (ft_toupper(cur->c) > old_letter + 1)
				return (NULL);
			if (ft_isupper(cur->c) && cur->c == old_letter + 1)
			{
				n = cur->n - m_lst[0]->n;
				return (m_lst + n);
			}
		}
		cur = cur->d;
	}
	return (NULL);
}
