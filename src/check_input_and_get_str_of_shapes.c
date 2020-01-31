/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_and_get_str_of_shapes.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:39:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/31 17:29:23 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define CHECK_ERROR -1
#define CHECK_SUCCESS 1

#define MAX_INPUT_LINES ((4 + 1) * 26)

int	check_tetr(char **t, int *x, int *x1, int *y1)
{
	int		line;
	int		n_block;
	int		y;

	line = 0;
	n_block = 0;
	y = 0;
	while (line < 4)
	{
		if (!t[*x])
			return (-1);
		if (y == 4)
		{
			if (t[*x][y] == '\0')
			{
				y = 0;
				line += 1;
				*x += 1;
				continue ;
			}
			else
				return (-1);
		}
		if (t[*x][y] == '.')
		{
			y++;
			continue ;
		}
		if (t[*x][y] == '#' && \
			(t[*x][y + 1] == '#' || t[*x][y - 1] == '#' || \
			 t[*x + 1][y] == '#' || t[*x - 1][y] == '#'))
		{
			x1[n_block] = *x;
			y1[n_block] = y;
			n_block += 1;
			y += 1;
		}
	}
	if (n_block != 4)
		return (-1);
	return (0);
}

int	check_input_and_recognise_shapes(char **t, char *shapes)
{
	int		x;
	int		n_tetr;
	int		y1[4];
	int		x1[4];

	printf("I'm here!\n");
	n_tetr = 0;
	x = -1;
	printf("t[%d][%d] = %c\n", x, 0, t[x][0]);
	while (1)
	{
		printf("recogn: shapes = %s\n", shapes);
		if (check_tetr(t, &x, x1, y1) == -1)
			return (-1);
		if (!t[x] || t[x][0] != '\0')
			return (-1);
		n_tetr += 1;
		if (n_tetr > 26)
			return (-1);
		ft_strcat(shapes, get_tetr_shape_type(x1, y1));
	}
	return (0);
}

int	check_input_and_get_str_of_shapes(int const fd, char *shapes)
{
	char	**t;
	int		i;
	int		j;

	if (!(t = (char **)malloc(MAX_INPUT_LINES * sizeof(char *))))
		return (CHECK_ERROR);
	t[(i = 0)] = ft_strnew(6);
	while (get_next_line(fd, t + i))
		t[++i] = ft_strnew(6);
	t[i] = NULL;
	j = 0;
	while (j < i)
	{
		printf("%2d: %s\n", j, t[j]);
		j += 1;
	}
	printf("check: i = %d\n", i);
	if (check_input_and_recognise_shapes(t, shapes) == -1)
		return (CHECK_ERROR);
	return (CHECK_SUCCESS);
}
