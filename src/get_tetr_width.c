/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetr_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:46:26 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 20:46:31 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	get_tetr_width(char tetr_type, char tetr_subtype)
{
	int	width;

	width = 0;
	if (tetr_type == 'I' && tetr_subtype == '1')
		width = 1;
	else if (((tetr_type == 'Z' || tetr_type == 'T') && \
			(tetr_subtype == '3' || tetr_subtype == '4')) || \
			(tetr_type == 'L' && \
			(tetr_subtype >= '1' && tetr_subtype <= '4')) ||  \
			(tetr_type == 'O'))
		width = 2;
	else if (((tetr_type == 'Z' || tetr_type == 'T') && \
			(tetr_subtype == '1' || tetr_subtype == '2')) || \
			(tetr_type == 'L' && \
			(tetr_subtype >= '5' && tetr_subtype <= '8')))
		width = 3;
	else if (tetr_type == 'I' && \
			tetr_subtype == '2')
		width = 4;
	return (width);
}
