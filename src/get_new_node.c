/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:48:08 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:53:07 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node		*get_new_node(\
	unsigned int num_in_lst, char node_role, int x_val, int y_val)
{
	t_node		*cur;

	cur = (t_node *)malloc(sizeof(t_node));
	if (!cur)
		return (NULL);
	cur->n = num_in_lst;
	cur->u = NULL;
	cur->r = NULL;
	cur->d = NULL;
	cur->l = NULL;
	cur->s = NULL;
	cur->role = node_role;
	cur->x = x_val;
	cur->y = y_val;
	return (cur);
}
