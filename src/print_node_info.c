#include "fillit.h"

void	print_node_info(t_node *cur)
{
    printf("%c ==(%d,%d)== %c\n", cur->role, cur->x, cur->y, cur->role);



	if (cur->s)
    {
        printf("       %c   \n", (cur->s)->c);
    }
    else
    {
        printf("       -   \n");
    }



    if (cur->u)
    {
        printf("       %c   \n", (cur->u)->c);
    }
    else
    {
        printf("       -   \n");
    }



    if (cur->l)
    {
        printf("   %c   ", (cur->l)->c);
    }
    else
    {
        printf("   -   ");
    }



	if (cur)
    {
        printf("%c   ", cur->c);
    }
    else
    {
        printf("-   ");
    }



	if (cur->r)
    {
        printf("%c\n", (cur->r)->c);
    }
    else
    {
        printf("-\n");
    }



	if (cur->d)
    {
        printf("       %c   \n\n", (cur->d)->c);
    }
    else
    {
        printf("       -   \n\n");
    }
}
