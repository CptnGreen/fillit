/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:44:49 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:44:55 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insert_node(t_node *node)
{
	t_node	*tmp;

	if (ft_islower(node->c))
	{
		tmp = node->u;
		tmp->d = node;
		tmp = node->d;
		tmp->u = node;
		node->c = ft_toupper(node->c);
	}
}
