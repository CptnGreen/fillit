/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:54:52 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/27 23:55:00 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_node(t_node *node)
{
	t_node	*tmp;

	if (ft_isupper(node->c))
	{
		tmp = node->u;
		tmp->d = node->d;
		tmp = node->d;
		tmp->u = node->u;
		node->c = ft_tolower(node->c);
	}
}
