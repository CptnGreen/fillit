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
