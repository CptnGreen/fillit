/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_and_get_str_of_shapes.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:39:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 05:10:56 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define CHECK_ERROR -1
#define CHECK_SUCCESS 1

#define MAX_INPUT_LINES ((4 + 1) * 26)

/*
** Функция получает проверяет 4 строки на то, являются ли они валидной
** репрезантацией тетреминки.
*/

int	count_block_connections(char **t, int x, int y, int line)
{
	int		n_block_connections;

	n_block_connections = 0;
	if (y + 1 < 4 && t[x] && t[x][y + 1] == '#')
		n_block_connections += 1;
	if (y - 1 >= 0 && t[x] && t[x][y - 1] == '#')
		n_block_connections += 1;
	if (line + 1 < 4 && t[x + 1] && t[x + 1][y] == '#')
		n_block_connections += 1;
	if (line - 1 >= 0 && t[x - 1] && t[x - 1][y] == '#')
		n_block_connections += 1;
	if (n_block_connections == 0)
		return (-1);
	return (n_block_connections);
}

int	check_tetr(char **t, int *x, int *x1, int *y1)
{
	int		line;
	int		n_block;
	int		y;
	int		n_tetr_connections;

	line = 0;
	n_block = 0;
	y = 0;
	n_tetr_connections = 0;
	while (line < 4 && t[*x])
	{
		if (y == 4)
		{
			if (t[*x][y] == '\0')
			{
				y = 0;
				line += 1;
				*x += 1;
				continue ;
			}
			return (-1);
		}
		else if (t[*x][y] == '.')
			y++;
		else if (t[*x][y] == '#')
		{
			n_tetr_connections += count_block_connections(t, *x, y, line);
			x1[n_block] = *x;
			y1[n_block] = y;
			n_block += 1;
			if (n_block > 4)
				return (-1);
			y += 1;
		}
		else
			return (-1);
	}
	if (n_block != 4 || n_tetr_connections < 6)
		return (-1);
	return (0);
}

int	check_input_and_recognise_shapes(char **t, char *shapes)
{
	int		x;
	int		n_tetr;
	int		y1[4];
	int		x1[4];

	n_tetr = 0;
	x = 0;
	while (1)
	{
		if (check_tetr(t, &x, x1, y1) == -1)
			return (-1);
		ft_strcat(shapes, get_tetr_shape_type(x1, y1));
		if (!t[x])
			return (0);
		if (t[x][0] != '\0')
			return (-1);
		x += 1;
		n_tetr += 1;
		if (n_tetr > 26)
			return (-1);
	}
	return (0);
}

int	check_input_and_get_str_of_shapes(int const fd, char *shapes)
{
	char	**t;
	int		i;

	if (!(t = (char **)malloc(MAX_INPUT_LINES * sizeof(char *))))
		return (CHECK_ERROR);
	t[(i = 0)] = ft_strnew(6);
	while (get_next_line(fd, t + i))
		t[++i] = ft_strnew(6);
	t[i] = NULL;
	if (check_input_and_recognise_shapes(t, shapes) == -1)
		return (CHECK_ERROR);
	return (CHECK_SUCCESS);
}
