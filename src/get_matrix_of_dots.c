/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_of_dots.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:34:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:38:11 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
