/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetr_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:42:08 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/02 23:30:17 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_tetr_sign_l(char tetr_type, char tetr_subtype)
{
	if (tetr_type == 'L')
	{
		if (tetr_subtype == '1')
			return ("00102021");
		else if (tetr_subtype == '2')
			return ("01112021");
		else if (tetr_subtype == '3')
			return ("00011020");
		else if (tetr_subtype == '4')
			return ("00011121");
		else if (tetr_subtype == '5')
			return ("00010210");
		else if (tetr_subtype == '6')
			return ("00010212");
		else if (tetr_subtype == '7')
			return ("00101112");
		else if (tetr_subtype == '8')
			return ("02101112");
	}
	return ("00000000");
}

char	*get_tetr_sign_zo(char tetr_type, char tetr_subtype)
{
	if (tetr_type == 'Z')
	{
		if (tetr_subtype == '1')
			return ("00011112");
		else if (tetr_subtype == '2')
			return ("01021011");
		else if (tetr_subtype == '3')
			return ("00101121");
		else if (tetr_subtype == '4')
			return ("01101120");
	}
	else if (tetr_type == 'O')
	{
		if (tetr_subtype == '1')
			return ("00011011");
	}
	return ("00000000");
}

char	*get_tetr_sign_ti(char tetr_type, char tetr_subtype)
{
	if (tetr_type == 'T')
	{
		if (tetr_subtype == '1')
			return ("00010211");
		else if (tetr_subtype == '2')
			return ("01101112");
		else if (tetr_subtype == '3')
			return ("00101120");
		else if (tetr_subtype == '4')
			return ("01101121");
	}
	else if (tetr_type == 'I')
	{
		if (tetr_subtype == '1')
			return ("00102030");
		else if (tetr_subtype == '2')
			return ("00010203");
	}
	return ("00000000");
}

char	*get_tetr_sign(char tetr_type, char tetr_subtype)
{
	if (tetr_type == 'L')
		return (get_tetr_sign_l(tetr_type, tetr_subtype));
	else if (tetr_type == 'Z' || tetr_type == 'O')
		return (get_tetr_sign_zo(tetr_type, tetr_subtype));
	else if (tetr_type == 'T' || tetr_type == 'I')
		return (get_tetr_sign_ti(tetr_type, tetr_subtype));
	return ("00000000");
}
