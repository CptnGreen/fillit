/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:45:38 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 20:45:42 by slisandr         ###   ########.fr       */
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
