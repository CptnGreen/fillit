/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:55:05 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/06 00:12:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <math.h> // remove later!
# include <stdio.h> // remove later!
# include <time.h> // remove later!

# include "../libft/libft.h"

# define POSSIBLE_SHAPES (									\
		tetr_subtype >= '1' &&								\
		(													\
			(tetr_type == 'L' && tetr_subtype <= '8') ||	\
			(tetr_type == 'Z' && tetr_subtype <= '4') ||	\
			(tetr_type == 'T' && tetr_subtype <= '4') ||	\
			(tetr_type == 'I' && tetr_subtype <= '2') ||	\
			(tetr_type == 'O' && tetr_subtype <= '1' )		\
			))

# define MIN_OF_TWO(Value1, Value2) ((Value1 < Value2) ? (Value1) : (Value2))
# define MAX_OF_TWO(Value1, Value2) ((Value1 > Value2) ? (Value1) : (Value2))
# define ABS(Value) ((Value >= 0) ? (Value) : (Value * (-1)))

# define CORRECT 0
# define WRONG 1

# define SUCCESS 1
# define FAILURE 0

# define OPTS 0
# define CHOS 1
# define TETR_ALL 2
# define TETR_PRES 3

/*
** Направления: u - up, r - right, d - down, l - left, s - super;
** Роли узлов (role): b - block, s - spacer, h - header, z - zero node.
*/

typedef struct			s_node{
	struct s_node		*u;
	struct s_node		*r;
	struct s_node		*d;
	struct s_node		*l;
	struct s_node		*s;
	char				c;
	char				role;
	int		x;
	int		y;
	unsigned int		n;
}						t_node;

/*
** Tetrimino analysis:
*/

char					*get_tetr_sign(char tetr_type, char tetr_subtype);
unsigned int			get_tetr_height(char tetr_type, char tetr_subtype);
unsigned int			get_tetr_width(char tetr_type, char tetr_subtype);
int						get_number_of_options_for_tetrimino(\
							unsigned int a, unsigned int h, unsigned int w);

int						check_input_and_get_str_of_shapes(\
							int const fd, char *shapes);

/*
** Structures:
*/

char					*get_sequence_of_shape_types(int *i, int *l);

char					**get_submatrix_for_tetr(\
							unsigned int sq_side, char tetr_type, \
							char tetr_subtype, unsigned int num_in_seq);

char					**compose_mstr_of_opts_from_shapes_str(\
							unsigned int sq_side, \
							char *shapes);

t_node					*get_new_node(\
							unsigned int num_in_lst, char role, \
							char character, int x_val, int y_val);

t_node					**get_mlst_from_mstr(char **m_str);

char					**opts_lst_to_square_str(\
							t_node **m_lst, int sq_side);

char					**get_matrix_of_dots(\
							unsigned int rows, unsigned int cols);
char					**join_matrices_str(char **m1, char **m2);
void					wipe_mstr(char **m);

/*
** Sizes:
*/

int						get_number_of_items(unsigned int square_side);

size_t					get_mstr_w(char **m);
size_t					get_mstr_h(char **m);
int						get_mlst_w(t_node **m_lst);
int						get_mlst_h(t_node **m_lst);

int						get_n_of_opts_in_mlst(t_node **m_lst);
int						get_num_of_tetr_mlst(t_node **m_lst);
int						get_num_of_tetr_mlst_conseq(t_node **m_lst);

/*
** Debugging:
*/

void					print_matrix_str(char **matrix);
void					print_matrix_lst_conseq(t_node **);
void					print_node_info(t_node *node);
void					print_all_nodes_mlst(t_node **m_lst);

/*
** Algorythm X:
*/

void	choose_option(t_node **m_lst, int n_opt);
void	cover_item_except_one_opt(t_node **m_lst, int n_item, int n_opt);
void	cover_item_of_node(t_node **m_lst, t_node *node);
void	cover_option_of_node(t_node **m_lst, t_node *node);
void	delete_node(t_node *node);
int		get_best_opts(t_node **m_lst);
void	update_mlst_status(t_node **m_lst, int *n_of);
int		get_first_block_num_in_option(t_node **m_lst, int n_opt);
int		get_last_block_num_in_option(t_node **m_lst, int n_opt);
void	insert_node(t_node *node);
void	unchoose_option(t_node **m_lst, int n_opt);
void	uncover_item_of_node(t_node **m_lst, t_node *node);
void	uncover_option_of_node(t_node **m_lst, t_node *node);

int		gbo(t_node **m_lst);
t_node	**get_next_submatrix_ptr(t_node **m_lst, int i);
int		skip_to_next_unempty_opt(t_node **m_lst, int *index);

#endif
