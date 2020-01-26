#include "fillit.h"

t_node	 *exclude_node(t_node *node)
{
    t_node *tmp;

    tmp = node->u;
    tmp->d = node->d;
    tmp = node->d;
    tmp->u = node->u;

	return (node);
}
