/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_items.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:43:34 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 22:43:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define ERROR_CODE -1

int	get_number_of_items(unsigned int square_side)
{
	return (square_side * square_side);
}
