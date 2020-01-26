#include "fillit.h"

size_t	get_mstr_w(char **m)
{
    if (m[0])
        return (ft_strlen(m[0]));
    else
        return (0);
}
