/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_blocks_in_mstr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:44:51 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:44:52 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		get_num_of_blocks_in_mstr(char **m)
{
	size_t	num;
	int		i;
	int		j;

	num = 0;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] != '.')
				num++;
			j++;
		}
		i++;
	}
	return (num);
}
