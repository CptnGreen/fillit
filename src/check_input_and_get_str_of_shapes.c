/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_and_get_str_of_shapes.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:49:00 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 10:26:04 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int	check_if_endl(char **t, int *x, int *y)
{
	if (t[*x][*y] == '\0')
	{
		*y = 0;
		*x += 1;
		return (1);
	}
	return (0);
}

int	check_tetr(char **t, int *x, int *x1, int *y1)
{
	int		n_block;
	int		y;
	int		n_tetr_connections;

	n_block = 0;
	y = 0;
	n_tetr_connections = 0;
	while ((*x % 5) < 4 && t[*x])
	{
		if (y != 4 && t[*x][y] == '.')
			y++;
		else if (y != 4 && t[*x][y] == '#')
		{
			n_tetr_connections += count_block_connections(t, *x, y, *x % 5);
			x1[n_block] = *x;
			y1[n_block] = y++;
			if (++n_block > 4)
				return (-1);
		}
		else if (y == 4 && check_if_endl(t, x, &y))
			continue ;
		else
			return (-1);
	}
	return (((n_block != 4 || n_tetr_connections < 6) ? (-1) : (0)));
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

/*
** 130 = 26 * 5
*/

int	check_input_and_get_str_of_shapes(int const fd, char *shapes)
{
	char	**t;
	int		i;

	if (!(t = (char **)malloc(130 * sizeof(char *))))
	{
		free(t);
		return (0);
	}
	t[0] = ft_strnew(6);
	i = 0;
	while (get_next_line(fd, t + i))
		t[++i] = ft_strnew(6);
	t[i] = 0;
	if (check_input_and_recognise_shapes(t, shapes) == -1)
	{
		wipe_mstr(t);
		return (0);
	}
	wipe_mstr(t);
	return (1);
}
