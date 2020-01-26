#include "fillit.h"

/*
** Функция принимает на вход 3 параметра: (1) сторону квадрата a,
** подматрицу для которого нужно построить, а также (2) высоту h и
** (3) ширину w тетриминки, для которой будет рассчитываться количество
** вариантов размещения в квадрате указанной величины.
*/

#define ERROR_CODE (-1)

#define MIN 1
#define MAX 4

int	get_number_of_options_for_tetrimino(\
  unsigned int a, unsigned int h, unsigned int w)
{
  unsigned int	num;

  if (h >= MIN && h <= MAX && w >= MIN && w <= MAX &&\
      ((num = ((a - (h - 1)) * (a - (w - 1)))) > 0))
  {
    /* printf("number of options = %d\n", num); // remove later! */
    return (num);
  }
  else
    return (ERROR_CODE);
}
