#include "fillit.h"

/*
** Применение этой функции на уже удалённом узле
** ничего не меняет!
*/

void	delete_node(t_node *node)
{
	t_node	*tmp;

	if (ft_isupper(node->c))
	{
		/* node->d->s = node; */
		tmp = node->u;
		tmp->d = node->d;
		tmp = node->d;
		tmp->u = node->u;
		node->c = ft_tolower(node->c);
	}
}
