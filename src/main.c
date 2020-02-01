/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:45:48 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 10:46:51 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		main(int argc, char **argv)
{
	int			fd;
	t_node		**m_lst;
	char		*shapes;
	int			sq_side;
	int			n_of[4];

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	shapes = ft_strnew(26 * 2);
	if (!check_input_and_get_str_of_shapes(fd, shapes))
	{
		ft_putendl("error");
		ft_strdel(&shapes);
		close(fd);
		return (1);
	}
	close(fd);
	sq_side = get_min_sq_side(shapes);
	while (sq_side <= 21)
	{
		m_lst = get_mlst_from_mstr(get_opts_mstr(sq_side, shapes));
		if (gbo(m_lst, n_of))
		{
			print_mstr(opts_lst_to_square_str(m_lst, sq_side));
			break ;
		}
		sq_side += 1;
	}
	ft_strdel(&shapes);
	return (0);
}
