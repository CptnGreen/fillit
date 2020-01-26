#include "fillit.h"

/*
** Эта функция принимает на вход матрицу в виде списка и
** определяет в ней количество строк и столбцов.
** Затем создаёт матрицу соответствующего размера,
** проходит по всему списку, отыскивая в нём
** узлы, содержащие блоки и, наконец, по заложенным в них
** коррдинатам вписывает в матрицу из точек нужные буквы.
*/

void    print_matrix_lst(t_node **m_lst)
{
    int		i;
    int		w;
    int		num_of_s;
    char	**m;

    i = w = num_of_s = 0;
    while (m_lst[i])
    {
        if (m_lst[i]->role == 's')
            num_of_s += 1;
        if (m_lst[i]->role == 'h')
            w++;
        i++;
    }
    m = get_matrix_of_dots(num_of_s, w);
    i = 0;
    while (m_lst[i])
    {
        if (m_lst[i]->role == 'b')
            m[m_lst[i]->x][m_lst[i]->y] = m_lst[i]->c;
        i++;
    }
    print_matrix_str(m);
}
