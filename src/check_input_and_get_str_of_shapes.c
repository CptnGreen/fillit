#include "fillit.h"

#define CHECK_ERROR -1
#define CHECK_SUCCESS 0

#define MAX_INPUT_LINES (((4 + 1) * 26) - 1)

char	*get_tetr_shape_type(int *i, int *l);
int	check_and_append_tetr_code_to_str(char **t, int rows, char *shapes);
int	check_tetr(char **t, int *x, int *x1, int *y1);
void	handle_block(int *x, int *y, int *x1, int *y1, int *i);

int	check_input_and_get_str_of_shapes(int const fd, char *shapes)
{
	char	**tetriminoes;
	int		i;
	int		res;

	tetriminoes = (char **)malloc(MAX_INPUT_LINES * sizeof(char *));
	if (!tetriminoes)
	{
		printf("error: this tetriminoes is not valid");
		return (0);
	}
	i = res = 0;
	tetriminoes[i] = ft_strnew(6);
	while (get_next_line(fd, tetriminoes + i))
		tetriminoes[++i] = ft_strnew(6);
	res = check_and_append_tetr_code_to_str(tetriminoes, i - 1, shapes);
	if (res == -1)
		printf("error: this tetrimino is not valid\n");
	return (CHECK_SUCCESS);
}

int	check_and_append_tetr_code_to_str(char **t, int rows, char *shapes)
{
	int		x;
	int		n_tetr;
	int		y1[4];
	int		x1[4];

	n_tetr = x = 0;
	while (x <= rows)
	{
		if (check_tetr(t, &x, x1, y1) == -1)
			return (-1);
		ft_strcat(shapes, get_tetr_shape_type(x1, y1));
		x += 1;
		if (++n_tetr > 26)
			return (-1);
	}
	return (0);
}

int	check_tetr(char **t, int *x, int *x1, int *y1)
{
	int		line;
	int		i;
	int		y;

	line = i = y = 0;
	while (line < 4)
	{
		if (t[*x][y] == '.')
			y++;
		else if (t[*x][y] == '#' && \
				 (t[*x][y + 1] == '#' || t[*x][y - 1] == '#' || \
				  t[*x + 1][y] == '#' || t[*x - 1][y] == '#'))
			handle_block(x, &y, x1, y1, &i);
		else if (y == 4)
		{
			y = 0;
			line++;
			*x += 1;
		}
		else
			return (-1);
	}
	if (i != 4 || t[*x][0] != '\0')
		return (-1);
	return (0);
}

void	handle_block(int *x, int *y, int *x1, int *y1, int *i)
{
	x1[*i] = *x;
	y1[*i] = *y;
	*i += 1;
	*y += 1;
}
