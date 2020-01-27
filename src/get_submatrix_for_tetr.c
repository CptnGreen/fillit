/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_submatrix_for_tetr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:33:05 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:33:37 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_submatrix(char **sub_matrix, unsigned int a, \
					   unsigned int start_row, char *sgn, char filler);


char	**get_submatrix_for_tetr(\
	unsigned int sq_side, \
	char tetr_type, \
	char tetr_subtype, \
	unsigned int num_in_seq)
{
	char					**sub_matrix;
	char					*row;
	unsigned int	num_of_options;
	unsigned int	num_of_items;
	char					*sgn;

	if (POSSIBLE_SHAPES)
	{
		num_of_items = get_number_of_items(sq_side);
		num_of_options = get_number_of_options_for_tetrimino(\
			sq_side, \
			get_tetr_height(tetr_type, tetr_subtype), \
			get_tetr_width(tetr_type, tetr_subtype));
		sub_matrix = get_matrix_of_dots(num_of_options, num_of_items);
		sgn = ft_strdup(get_tetr_sign(tetr_type, tetr_subtype));
		fill_submatrix(sub_matrix, sq_side, 0, sgn, num_in_seq + 'A');
		return (sub_matrix);
	}
	return (NULL);
}

void	fill_submatrix(char **sub_matrix, unsigned int a, \
					   unsigned int start_row, char *sgn, char filler)
{
	int						i;
	int						j;
	int						r;

	r = start_row;
	j = 0;
	while (sgn[0] + j - '0' <= (a - 1) && sgn[2] + j - '0' <= (a - 1) && \
		   sgn[4] + j - '0' <= (a - 1) && sgn[6] + j - '0' <= (a - 1))
	{
		i = 0;
		while (sgn[1] + i - '0' <= (a - 1) && sgn[3] + i - '0' <= (a - 1) && \
			   sgn[5] + i - '0' <= (a - 1) && sgn[7] + i - '0' <= (a - 1))
		{
			sub_matrix[r][a * (sgn[0] + j - '0') + (sgn[1] + i - '0')] = \
				sub_matrix[r][a * (sgn[2] + j - '0') + (sgn[3] + i - '0')] = \
				sub_matrix[r][a * (sgn[4] + j - '0') + (sgn[5] + i - '0')] = \
				sub_matrix[r][a * (sgn[6] + j - '0') + (sgn[7] + i - '0')] = \
				filler;
			i += 1;
			r += 1;
		}
		j += 1;
	}
}
