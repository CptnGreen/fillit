/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_mstr_of_opts_from_shapes_str.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:40:41 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:40:48 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**compose_mstr_of_opts_from_shapes_str(\
	unsigned int sq_side, \
	char *shapes)
{
	int			i;
	char		**m;

	i = 0;
	m = NULL;
	while (shapes[i])
	{
		if (m == NULL)
		{
			m = get_submatrix_for_tetr(\
				sq_side, shapes[i], shapes[i + 1], i / 2);
		}
		else
		{
			m = join_matrices_str(\
				m, get_submatrix_for_tetr(\
					sq_side, shapes[i], shapes[i + 1], i / 2));
		}
		i += 2;
	}
	return (m);
}
