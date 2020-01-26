#include "fillit.h"

unsigned int	get_tetr_height(char tetr_type, char tetr_subtype)
{
    int	height;

    height = 0;
    if (tetr_type == 'I' && tetr_subtype == '2')
        height = 1;
    else if (((tetr_type == 'Z' || tetr_type == 'T') && \
              (tetr_subtype == '1' || tetr_subtype == '2')) || \
             (tetr_type == 'L' && \
              (tetr_subtype >= '5' && tetr_subtype <= '8')) ||  \
             (tetr_type == 'O'))
        height = 2;
    else if (((tetr_type == 'Z' || tetr_type == 'T') && \
              (tetr_subtype == '3' || tetr_subtype == '4')) || \
             (tetr_type == 'L' && \
              (tetr_subtype >= '1' && tetr_subtype <= '4')))
        height = 3;
    else if (tetr_type == 'I' && \
             tetr_subtype == '1')
        height = 4;
    return (height);
}
