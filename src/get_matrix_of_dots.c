#include "fillit.h"

/*
** Функция возвращает матрицу размером rows x cols, заполненную
** точками. Каждая строка оканчивается символом '\0', ссылка на
** последнуюю строку указывает в NULL.
*/

char	**get_matrix_of_dots(unsigned int rows, unsigned int cols)
{
    char	**matrix;
    int		i;
    int		j;

    matrix = (char **)malloc((rows + 1) * sizeof(char *));
    i = 0;
    while (i < rows)
    {
        matrix[i] = ft_strnew(cols);
        j = 0;
        while (j < cols)
        {
            matrix[i][j] = '.';
            j++;
        }
        i++;
    }
    matrix[i] = NULL;
    return (matrix);
}
