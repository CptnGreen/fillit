#include "fillit.h"

char	*get_tetr_shape_type(int *i, int *l);
int		check_and_append_tetr_code_to_str(\
        char **tetriminoes, int str, char *shapes);

int	check_input_and_get_str_of_shapes(int const fd, char *shapes)
{
    char	**tetriminoes;
    int		i;
    int		res;

    tetriminoes = (char **)malloc(131 * sizeof(char *));
    if (!tetriminoes)
    {
        printf("error: this tetriminoes is not valid");
        return (0);
    }
    res = 0;
    i = 0;
    tetriminoes[i] = ft_strnew(6);
    while (get_next_line(fd, tetriminoes + i))
        tetriminoes[++i] = ft_strnew(6);
    res = check_and_append_tetr_code_to_str(tetriminoes, i - 1, shapes);
    if (res == -1)
        printf("error: this tetrimino is not valid\n");
    return (0);
}

int	check_and_append_tetr_code_to_str(\
	char **tetriminoes, int str, char *shapes)
{
    int	i;
    int	l;
    int	k;
    int	tet;
    int	line;
    int	l1[4];
    int	i1[4];
    int	i2;

    i2 = 0;
    line = 1;
    tet = 0;
    k = 0;
    l = 0;
    i = 0;
    while (i <= str)
    {
        while (line < 5)
        {
            if (tetriminoes[i][l] == '.')
                l++;
            else if (tetriminoes[i][l] == '#' && \
                     (tetriminoes[i][l + 1] == '#' || \
                      tetriminoes[i][l - 1] == '#' || \
                      tetriminoes[i + 1][l] == '#' || \
                      tetriminoes[i - 1][l] == '#'))
            {
                l1[k] = l;
                i1[i2] = i;
                i2++;
                l++;
                k++;
            }
            else if (l == 4)
            {
                l = 0;
                line++;
                i++;
            }
            else
                return(-1);
        }
        if (k != 4 || tetriminoes[i][0] != '\0' || tet > 26)
            return (-1);
        else
        {
            i++;
            line = 1;
            ft_strcat(shapes, get_tetr_shape_type(i1, l1));
            i2 = 0;
            tet++;
            l = 0;
            k = 0;
        }
        printf(" ");
    }
    printf("\n");
    return (0);
}
