/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_and_get_str_of_shapes.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:39:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 03:29:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define CHECK_ERROR -1
#define CHECK_SUCCESS 1

#define MAX_INPUT_LINES (((4 + 1) * 26) - 1)

char	*get_tetr_shape_type(int *i, int *l);
int	check_input_and_recognise_shapes(char **t, int rows, char *shapes);
int	check_tetr(char **t, int *x, int *x1, int *y1);
void	handle_block(int *x, int *y, int *x1, int *y1, int *i);

int	check_input_and_get_str_of_shapes(int const fd, char *shapes)
{
	char	**t;
	int		i;
	int		res;

	t = (char **)malloc(MAX_INPUT_LINES * sizeof(char *));
	if (!t)
		return (CHECK_ERROR);
	i = 0;
	res = 0;
	t[i] = ft_strnew(6);
	while (get_next_line(fd, t + i))
		t[++i] = ft_strnew(6);
	/* if (t[i][0] != '#' || t[i][0] != '.') */
	/* 	return (CHECK_ERROR); */
	res = check_input_and_recognise_shapes(t, i - 1, shapes);
	if (res == -1)
		return (CHECK_ERROR);
	return (CHECK_SUCCESS);
}

int	check_input_and_recognise_shapes(char **t, int rows, char *shapes)
{
	int		x;
	int		n_tetr;
	int		y1[4];
	int		x1[4];

	n_tetr = 0;
	x = 0;
	while (x <= rows)
	{
		if (check_tetr(t, &x, x1, y1) == -1)
			return (-1);
		ft_strcat(shapes, get_tetr_shape_type(x1, y1));
		x += 1;
		if (++n_tetr > 26)
			return (-1);
	}
	if (x == rows && t[x][0] == '\0')
		return (-1);
	return (0);
}

int	check_tetr(char **t, int *x, int *x1, int *y1)
{
	int		line;
	int		n_blocks;
	int		y;

	line = 0;
	n_blocks = 0;
	y = 0;
	while (line < 4)
	{
		if (t[*x][y] == '.')
			y++;
		else if (t[*x][y] == '#' && \
				 (t[*x][y + 1] == '#' || t[*x][y - 1] == '#' || \
				  t[*x + 1][y] == '#' || t[*x - 1][y] == '#'))
			handle_block(x, &y, x1, y1, &n_blocks);
		else if (y == 4)
		{
			y = 0;
			line++;
			*x += 1;
		}
		else
			return (-1);
	}
	if (n_blocks != 4 || t[*x][0] != '\0')
		return (-1);
	return (0);
}

void	handle_block(int *x, int *y, int *x1, int *y1, int *n_blocks)
{
	x1[*n_blocks] = *x;
	y1[*n_blocks] = *y;
	*n_blocks += 1;
	*y += 1;
}
