/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_mstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@google.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:44:38 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 03:45:49 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	wipe_mstr(char **m)
{
	int		i;

	i = 0;
	while (m[i])
	{
		ft_strdel(m + i);
		i++;
	}
	free(m);
	m = NULL;
}
