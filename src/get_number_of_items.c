/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_items.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:43:42 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:43:48 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define ERROR_CODE (-1)

int	get_number_of_items(unsigned int square_side)
{
	return (square_side * square_side);
}
