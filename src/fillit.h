/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:18:22 by slisandr          #+#    #+#             */
/*   Updated: 2020/01/31 16:53:55 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <time.h> // remove later!
# include <stdio.h> // remove later!
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
# define CORRECT 0
# define WRONG 1
# define SUCCESS 1
# define FAILURE 0
# define OPTS 0
# define CHOS 1
# define TETR_ALL 2
# define TETR_PRES 3

typedef struct			s_node{
	struct s_node		*u;
	struct s_node		*r;
	struct s_node		*d;
	struct s_node		*l;
	struct s_node		*s;
	char				c;
	char				role;
	int					x;
	int					y;
	unsigned int		n;
}						t_node;

char					*get_tetr_sign(char tetr_type, char tetr_subtype);
unsigned int			get_tetr_height(char tetr_type, char tetr_subtype);
unsigned int			get_tetr_width(char tetr_type, char tetr_subtype);
int						get_number_of_options_for_tetrimino(\
	unsigned int a, unsigned int h, unsigned int w);
int						check_input_and_get_str_of_shapes(\
	int const fd, char *shapes);
char					*get_sequence_of_shape_types(int *i, int *l);
char					**get_submatrix_for_tetr(\
	unsigned int sq_side, char tetr_type, \
	char tetr_subtype, unsigned int num_in_seq);
char					**compose_mstr_of_opts_from_shapes_str(\
	unsigned int sq_side, \
	char *shapes);
t_node					*get_new_node(unsigned int num_in_lst, char role, \
	int x_val, int y_val);
t_node					**get_mlst_from_mstr(char **m_str);
char					**opts_lst_to_square_str(\
	t_node **m_lst, int sq_side);
char					**get_matrix_of_dots(\
	unsigned int rows, unsigned int cols);
char					**join_matrices_str(char **m1, char **m2);
void					wipe_mstr(char **m);
int						get_number_of_items(unsigned int square_side);
size_t					get_mstr_w(char **m);
size_t					get_mstr_h(char **m);
int						get_mlst_w(t_node **m_lst);
int						get_mlst_h(t_node **m_lst);
int						get_n_of_opts_in_mlst(t_node **m_lst);
int						get_num_of_tetr_mlst(t_node **m_lst);
int						get_num_of_tetr_mlst_conseq(t_node **m_lst);
void					choose_option(t_node **m_lst, int n_opt);
void					cover_item_except_one_opt(t_node **m_lst, \
												  int n_item, int n_opt);
void					cover_item(t_node **m_lst, t_node *node);
void					cover_option_of_node(t_node **m_lst, t_node *node);
void					delete_node(t_node *node);
int						get_best_opts(t_node **m_lst);
void					update_mlst_status(t_node **m_lst, int *n_of);
void					insert_node(t_node *node);
void					unchoose_option(t_node **m_lst, int n_opt);
void					uncover_item(t_node **m_lst, t_node *node);
void					uncover_option_of_node(t_node **m_lst, t_node *node);
int						gbo(t_node **m_lst);
t_node					**get_next_submatrix_ptr(t_node **m_lst, int i);
int						skip_to_next_unempty_opt(t_node **m_lst, int *index);
void					print_mstr(char **matrix);
size_t					get_num_of_blocks_in_mstr(char **m);
void					create_vert_connections_in_mlst(t_node **m_lst);
void					connect_nodes_vert(t_node *down, t_node *up);
void					translate_blocks_and_spacers(\
	t_node **m_lst, char **m_str, size_t w, size_t n);
char	*get_tetr_shape_type(int *i, int *l);

#endif
