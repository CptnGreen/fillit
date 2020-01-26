#include "fillit.h"

/*
** INPUT:  ссылка на начало "старой" подматрицы и (относительный)
**         номер спейсера в начале очередной выбранной строки в
**         этой подматрице
**
** OUTPUT: ссылка на начало (на первый спейсер) подматрицы с
**         очередным символом или NULL, если такую подматрицу
**         найти не удалось
*/

t_node		**get_next_submatrix_ptr(t_node **m_lst, int i)
{
	char	old_letter;
	t_node	*cur;
	int		n;

	cur = m_lst[i];
	old_letter = ft_toupper(cur->r->c);
	while (cur->c != '$' && cur->role != 'z')
	{
		if (cur->c != '*')
		{
			if (ft_toupper(cur->c) > old_letter + 1)
				return (NULL);
			if (ft_isupper(cur->c) && cur->c == old_letter + 1)
			{
				n = cur->n - m_lst[0]->n;
				return (m_lst + n);
			}
		}
		cur = cur->d;
	}
	return (NULL);
}
