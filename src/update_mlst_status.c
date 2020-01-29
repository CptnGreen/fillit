/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mlst_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:00:41 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 20:01:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	reset_vars(int *n_of, char *c_prev_pres, char *c_prev_all)
{
	n_of[OPTS] = 0;
	n_of[TETR_ALL] = 0;
	n_of[TETR_PRES] = 0;
	n_of[CHOS] = 0;
	*c_prev_pres = 'A' - 1;
	*c_prev_all = 'A' - 1;
}

void	update_mlst_status(t_node **m_lst, int *n_of)
{
	char	c_prev_all;
	char	c_prev_pres;
	t_node	*cur;
	char	letter;

	reset_vars(n_of, &c_prev_pres, &c_prev_all);
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
		if (ft_toupper(cur->c) > ft_toupper(c_prev_all))
		{
			n_of[TETR_ALL] += 1;
			c_prev_all = ft_toupper(cur->r->c);
		}
		cur = cur->d;
	}
}
