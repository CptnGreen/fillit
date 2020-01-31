/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:45:48 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/31 17:00:04 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_min_sq_side(char *shapes);

#define ERROR 1
#define FINISH 0

#define MAX_N_OF_TETR 26
#define MAX_SQ_SIDE 20

int		main(int argc, char **argv)
{
	int			fd;
	char		**m_str;
	t_node		**m_lst;
	char		*shapes;
	int			sq_side;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error 1");
		return (FAILURE);
	}
	shapes = ft_strnew(MAX_N_OF_TETR * 2);
	if (check_input_and_get_str_of_shapes(fd, shapes) == -1)
	{
		ft_putendl("error 2");
		return (ERROR);
	}
	printf("shapes: %s\n", shapes);
	close(fd);
	sq_side = get_min_sq_side(shapes);
	while (sq_side <= MAX_SQ_SIDE)
	{
		m_str = compose_mstr_of_opts_from_shapes_str(sq_side, shapes);
		m_lst = get_mlst_from_mstr(m_str);
		if (gbo(m_lst))
		{
			m_str = opts_lst_to_square_str(m_lst, sq_side);
			print_mstr(m_str);
			break ;
		}
		sq_side += 1;
	}
	return (FINISH);
}

int		get_min_sq_side(char *shapes)
{
	int	n_tetr;
	int	sq_side;
	int	len;

	len = ft_strlen(shapes);
	n_tetr = (len / 2);
	if (len == 1 && ft_strchr(shapes, 'O'))
		sq_side = 2;
	else if (ft_strchr(shapes, 'I'))
		sq_side = 4;
	else
		sq_side = 3;
	while (n_tetr * 4 > sq_side * sq_side)
		sq_side += 1;
	return (sq_side);
}
