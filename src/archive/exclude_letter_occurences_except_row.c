#include "fillit.h"

/*
** Эта функция последовательно проходит по всем столбцам
** сверху вниз, ищет узлы с нужной буквой (но не из строки
** row) и исключает их из списка. Возвращает последний
** исключённый узел.
*/

t_node	*exclude_letter_occurences_except_row(\
	t_node **m_lst, char letter, int row)
{
	t_node	*last_excl;
	t_node	*cur;

	last_excl = NULL;
	cur = m_lst[1];
	while (cur->role != 'z')
	{
		cur = cur->d;
		if (cur->role == 'h')
		{
			cur = cur->r;
			continue ;
		}
		else if ((cur->x != row) && (cur->c == letter))
		    last_excl = cover_option(m_lst, cur->x);
	}
	return (last_excl);
}
