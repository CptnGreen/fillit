#include "fillit.h"

int		skip_to_next_unempty_opt(t_node **m_lst, int *index)
{
	t_node	*cur;
	char	letter;

	printf("skipping from (i = %d) ...\n", *index);
	print_node_info(m_lst[*index]);

	letter = (m_lst[*index]->c == '*') ? \
		ft_toupper((m_lst[*index]->r->c)) : ft_toupper((m_lst[*index]->c));
	cur = (m_lst[0]->role == 'z') ? (m_lst[0]->d) : (m_lst[0]);
	while (cur->role != 'z')
	{
		if (cur->c == '$' || ft_toupper(cur->c) > letter)
		{
			printf("... to nothing - no more open lines!\n");
			return (FAILURE);
		}
		if (ft_isupper(cur->c) && cur->x > m_lst[*index]->x)
		{
			*index = cur->n - m_lst[0]->n;
			printf("... to (i = %d) \n", *index);
			print_node_info(cur);
			return (SUCCESS);
		}
		cur = cur->d;
	}

	return (FAILURE);
}

/* int		skip_to_next_unempty_opt(t_node **m_lst, int *index) */
/* { */
/* 	int		i; */
/* 	t_node	*cur; */
/* 	char	last_letter; */

/* 	i = *index; */
/* 	cur = m_lst[i]; */
/* 	printf("skip: i = %d\n", i); */
/* 	print_node_info(cur); */
/* 	if (cur->role == 'h') */
/* 	{ */
/* 		while (cur->role != 'z') */
/* 			cur = cur->r; */
/* 	} */
/* 	if (cur->role == 'b') */
/* 		cur = cur->l; */
/* 	if (cur->c == '$') */
/* 		return (FAILURE); */
/* 	last_letter = ((cur->role == 'z') ? ('A') : (ft_toupper(cur->r->c))); */
/* 	cur = cur->d; */
/* 	i = cur->n - m_lst[0]->n; // + 1 ? */
/* 	if (cur->c == '$' || ft_toupper(cur->r->c) != last_letter) */
/* 		return (FAILURE); */
/* 	if (ft_isupper(cur->c) || skip_to_next_unempty_opt(m_lst, &i)) */
/* 	{ */
/* 		*index = i; */
/* 		return (SUCCESS); */
/* 	} */
/* 	return (FAILURE); */
/* } */
