#include "fillit.h"

/*
** Применение этой функции на неудалённом узле
** ничего не меняет!
*/

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
