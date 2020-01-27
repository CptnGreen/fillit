/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:45:48 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/28 02:17:58 by slisandr         ###   ########.fr       */
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
	int			n_of[4];

	clock_t		t;
	double		time_taken;

	t = clock();
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
		return (FAILURE);
	shapes = ft_strnew(MAX_N_OF_TETR * 2);
	if (check_input_and_get_str_of_shapes(fd, shapes) == -1)
		return (ERROR);
	close(fd);
	printf("Shapes (n = %d): %s\n\n", (int)(ft_strlen(shapes) / 2), shapes);
	sq_side = get_min_sq_side(shapes);
	while (sq_side <= MAX_SQ_SIDE)
	{
		m_str = compose_mstr_of_opts_from_shapes_str(sq_side, shapes);
		m_lst = get_mlst_from_mstr(m_str);
		if (gbo(m_lst))
		{
			update_mlst_status(m_lst, n_of);
			printf("Min sq_side = %d:\n\n", sq_side); // remove later!
			m_str = opts_lst_to_square_str(m_lst, sq_side);
			print_mstr(m_str);
			break ;
		}
		sq_side += 1;
	}
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("\nfillit took %f seconds to execute\n", time_taken);
	return (FINISH);
}

int		get_min_sq_side(char *shapes)
{
	int	n_tetr;
	int	sq_side;

	n_tetr = (ft_strlen(shapes) / 2);
	sq_side = 2;
	while (n_tetr * 4 > sq_side * sq_side)
		sq_side += 1;
	return (sq_side);
}
