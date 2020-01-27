/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mlst_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 01:53:43 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:00:10 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	handle_upper_letter(\
	int *n_of, t_node *cur, char *c_prev_pres, char letter);

void	update_mlst_status(t_node **m_lst, int *n_of)
{
	char	c_prev_all;
	char	c_prev_pres;
	t_node	*cur;
	char	letter;

	n_of[OPTS] = n_of[TETR_ALL] = n_of[TETR_PRES] = n_of[CHOS] = 0;
	c_prev_pres = c_prev_all = 'A' - 1;
	cur = (m_lst[0]->role == 'z') ? (m_lst[0]->d) : (m_lst[0]);
	while (cur->c != '$')
	{
		if (cur->c == '*')
		{
			letter = ft_toupper(cur->r->c);
			n_of[CHOS] += 1;
		}
		else if (ft_isupper(cur->c))
			handle_upper_letter(n_of, cur, &c_prev_pres, letter);
		else if (ft_toupper(cur->c) > ft_toupper(c_prev_all))
		{
			n_of[TETR_ALL] += 1;
			c_prev_all = ft_toupper(cur->r->c);
		}
		cur = cur->d;
	}
}

void	handle_upper_letter(\
	int *n_of, t_node *cur, char *c_prev_pres, char letter)
{
	n_of[OPTS] += 1;
	if (cur->r->c > ft_toupper(*c_prev_pres) && cur->r->c > letter)
	{
		n_of[TETR_PRES] += 1;
		*c_prev_pres = ft_toupper(cur->r->c);
	}
}
