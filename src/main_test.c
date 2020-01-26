
#include "fillit.h"

int		get_min_sq_side(char *shapes);

#define TEST_N 19
#define MAX_N_OF_TETR 26
#define MAX_SQ_SIDE 12

int		main(int argc, char **argv)
{
	int				fd;
	char			**m_str;
	t_node			**m_lst;
	char			*shapes;
	int				sq_side;
	int				n_of[4];
	int				i;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	shapes = ft_strnew(MAX_N_OF_TETR * 2);
	check_input_and_get_str_of_shapes(fd, shapes);
	close(fd);
	printf("Shapes: %s\n\n", shapes); // remove later!
	/* sq_side = get_min_sq_side(shapes); */
	sq_side = 4;
	m_str = compose_mstr_of_opts_from_shapes_str(sq_side, shapes);
  print_matrix_str(m_str);
	m_lst = get_mlst_from_mstr(m_str);
  printf("I'm here!\n");
	print_matrix_lst_conseq(m_lst);

	i = 0;
	while (i < 11)
		choose_option(m_lst, i++);

	m_str = opts_lst_to_square_str(m_lst, sq_side);
	print_matrix_str(m_str);

	i = 10;
	while (i >= 0)
		unchoose_option(m_lst, i--);
	print_matrix_lst_conseq(m_lst);

	update_mlst_status(m_lst, n_of);
	/* print_all_nodes_mlst(m_lst); */

	return (0);
}

int		get_min_sq_side(char *shapes)
{
	if (ft_strlen(shapes) == 2 && shapes[0] == 'O')
		return (2);
	else if (ft_strchr(shapes, 'I'))
		return (4);
	else
		return (3);
}
