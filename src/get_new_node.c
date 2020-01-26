/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:48:08 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/05 22:08:52 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**
*/

t_node		*get_new_node(\
	unsigned int num_in_lst, char node_role, char character, int x_val, int y_val)
{
	t_node		*cur;

	cur = (t_node *)malloc(sizeof(t_node));
	if (!cur)
		return (NULL);
	cur->n = num_in_lst;
	cur->u = cur->r = cur->d = cur->l = cur->s = NULL;
	cur->role = node_role;
	cur->c = character;
	cur->x = x_val;
	cur->y = y_val;
	return (cur);
}
