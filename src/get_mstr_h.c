#include "fillit.h"

size_t	get_mstr_h(char **m)
{
    int		i;

    i = 0;
    if (m)
    {
        while (m[i])
            i++;
    }
    return (i);
}
