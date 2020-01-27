/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:04:23 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:06:03 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_mstr(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_putendl(matrix[i]);
		i++;
	}
}
