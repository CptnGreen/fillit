/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_options_for_tetrimino.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:08:16 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 20:08:21 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define ERROR_CODE -1
#define MIN 1
#define MAX 4

int	get_number_of_options_for_tetrimino(\
	unsigned int a, unsigned int h, unsigned int w)
{
	unsigned int	num;

	if (h >= MIN && h <= MAX && w >= MIN && w <= MAX &&\
		((num = ((a - (h - 1)) * (a - (w - 1)))) > 0))
		return (num);
	else
		return (ERROR_CODE);
}
