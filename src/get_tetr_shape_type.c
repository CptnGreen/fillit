#include "fillit.h"

char	*get_tetr_shape_type_IO(int *i, int *l);
char	*get_tetr_shape_type_L(int *i, int *l);
char	*get_tetr_shape_type_TZ(int *i, int *l);

char	*get_tetr_shape_type(int *i, int *l)
{
    char	*status;

    if ((status = get_tetr_shape_type_IO(i, l)))
        return (status);
    else if ((status = get_tetr_shape_type_TZ(i, l)))
        return (status);
    else if ((status = get_tetr_shape_type_L(i, l)))
        return (status);
    else
        return ("Error");
}

char	*get_tetr_shape_type_IO(int *i, int *l)
{
    if (i[0] == i[1] && i[1] == i[2] && \
        i[2] == i[3] && l[1] - l[0] == 1 && \
        l[2] - l[1] == 1 && l[3] - l[2] == 1)
        return ("I2");
    else if (l[0] == l[1] && l[1] == l[2] && \
             l[2] == l[3] && i[1] - i[0] == 1 && \
             i[2] - i[1] == 1 && i[3] - i[2] == 1)
        return ("I1");
    else if (i[0] == i[1] && i[2] == i[3] && \
             i[1] != i[2] && l[0] == l[2])
        return ("O1");
    else
        return (NULL);
}

char	*get_tetr_shape_type_L(int *i, int *l)
{
    if (l[0] == l[1] && l[1] == l[2] && i[2] == i[3])
        return ("L1");
    else if (l[0] == l[1] && l[1] == l[3] && i[2] == i[3])
        return ("L2");
    else if (l[0] == l[3] && l[3] == l[2] && i[0] == i[1])
        return ("L3");
    else if (l[3] == l[1] && l[1] == l[2] && i[0] == i[1])
        return ("L4");
    else if (i[0] == i[1] && i[1] == i[2] && l[0] == l[3])
        return ("L5");
    else if (i[0] == i[1] && i[1] == i[2] && l[2] == l[3])
        return ("L6");
    else if (i[3] == i[1] && i[1] ==  i[2] && l[0] == l[1])
        return ("L7");
    else if (i[3] == i[1] && i[1] == i[2] && l[0] == l[3])
        return ("L8");
    else
        return (NULL);
}

char	*get_tetr_shape_type_TZ(int *i, int *l)
{
    if (i[0] == i[1] && i[2] == i[3] && l[2] == l[1])
        return ("Z1");
    else if (i[0] == i[1] && i[2] == i[3] && l[0] == l[3])
        return ("Z2");
    else if (i[2] == i[1] && l[1] == l[0] && l[2] == l[3])
        return ("Z3");
    else if (i[2] == i[1] && l[2] == l[0] && l[3] == l[1])
        return ("Z4");
    else if (i[0] == i[1] && i[1] == i[2] && i[2] != i[3] && \
             l[3] == l[1])
        return ("T1");
    else if (i[2] == i[1] &&  i[1] == i[3] && l[2] == l[0])
        return ("T2");
    else if (i[2] == i[1] && l[0] == l[3] && l[3] == l[1] && \
             l[2] != l[3])
        return ("T3");
    else if (l[0] == l[2] && l[2] == l[3] && l[3] != l[1] && \
             i[2] == i[1])
        return ("T4");
    else
        return (NULL);
}
