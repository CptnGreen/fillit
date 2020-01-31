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

void	handle_chosen(\
	int *n_of, t_node *cur, char *c_prev_pres, char *c_prev_all)
{
	n_of[CHOS] += 1;
	if (ft_toupper(cur->r->c) > *c_prev_all)
	{
		n_of[TETR_ALL] += 1;
		*c_prev_all = ft_toupper(cur->r->c);
	}
}

void	handle_covered(\
	int *n_of, t_node *cur, char *c_prev_pres, char *c_prev_all)
{
	if (ft_toupper(cur->c) > *c_prev_all)
	{
		n_of[TETR_ALL] += 1;
		*c_prev_all = ft_toupper(cur->r->c);
	}
}

void	handle_uncovered(\
	int *n_of, t_node *cur, char *c_prev_pres, char *c_prev_all)
{
	n_of[OPTS] += 1;
	if (cur->c > *c_prev_pres)
	{
		n_of[TETR_PRES] += 1;
		*c_prev_pres = ft_toupper(cur->c);
	}
	if (cur->c > *c_prev_all)
	{
		n_of[TETR_ALL] += 1;
		*c_prev_all = ft_toupper(cur->c);
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

	reset_vars(n_of, &c_prev_pres, &c_prev_all);
	cur = (m_lst[0]->role == 'z') ? (m_lst[0]->d) : (m_lst[0]);
	while (cur->c != '$')
	{
		if (ft_islower(cur->c))
			handle_covered(n_of, cur, &c_prev_pres, &c_prev_all);
		else if (ft_isupper(cur->c))
			handle_uncovered(n_of, cur, &c_prev_pres, &c_prev_all);
		else if (cur->c == '*')
			handle_chosen(n_of, cur, &c_prev_pres, &c_prev_all);
		cur = cur->d;
	}
}
