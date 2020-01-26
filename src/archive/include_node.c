#include "fillit.h"

void include_node(t_node *node)
{
    t_node *tmp;

    tmp = node->u;
    tmp->d = node;
    tmp = node->d;
    tmp->u = node;
}
