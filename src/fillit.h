/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:32:49 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 14:39:33 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define CORRECT 0
# define WRONG 1
# define SUCCESS 1
# define FAILURE 0
# define OPTS 0
# define CH 1
# define TA 2
# define TU 3

# include "../libft/libft.h"
# include "t_node.h"

char					*get_tetr_sign(char tetr_type, char tetr_subtype);
unsigned int			get_tetr_height(char tetr_type, char tetr_subtype);
unsigned int			get_tetr_width(char tetr_type, char tetr_subtype);
int						get_number_of_options_for_tetrimino(\
	unsigned int a, unsigned int h, unsigned int w);
int						check_input_and_get_str_of_shapes(\
	int const fd, char *shapes);
char					**get_submatrix_for_tetr(\
	unsigned int sq_side, char tetr_type, \
	char tetr_subtype, unsigned int num_in_seq);
char					**get_opts_mstr(\
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
void					choose_option(t_node **m_lst, int n_opt);
void					cover_item(t_node **m_lst, t_node *node);
void					cover_option_of_node(t_node **m_lst, t_node *node);
void					delete_node(t_node *node);
void					update_mlst_status(t_node **m_lst, int *n_of);
void					insert_node(t_node *node);
void					unchoose_option(t_node **m_lst, int n_opt);
void					uncover_item(t_node **m_lst, t_node *node);
void					uncover_option_of_node(t_node **m_lst, t_node *node);
int						gbo(t_node **m_lst, int *n_of);
t_node					**get_ptr(t_node **m_lst, int i);
int						skip(t_node **m_lst, int *index);
void					print_mstr(char **matrix);
size_t					get_num_of_blocks_in_mstr(char **m);
void					create_vert_connections_in_mlst(t_node **m_lst);
void					connect_nodes_vert(t_node *down, t_node *up);
void					translate_blocks_and_spacers(\
	t_node **m_lst, char **m_str, size_t w, size_t n);
char					*get_tetr_shape_type(int *i, int *l);
void					wipe_mlst(t_node **m_lst);

#endif
