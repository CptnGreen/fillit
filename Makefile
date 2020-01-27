#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 00:07:33 by slisandr          #+#    #+#              #
#    Updated: 2020/01/28 00:14:37 by slisandr         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all re clean fclean test

MAIN = src/main.c

TEST = tests/test

CFLAGS = -Wall -Werror -Wextra

EXEC = fillit

SRCS = \
src/get_number_of_options_for_tetrimino.c \
src/get_submatrix_for_tetr.c \
src/get_number_of_items.c \
src/print_mstr.c \
src/get_tetr_sign.c \
src/get_new_node.c \
src/get_matrix_of_dots.c \
src/get_mlst_from_mstr.c \
src/print_mlst.c \
src/get_tetr_shape_type.c \
src/join_matrices_str.c \
src/check_input_and_get_str_of_shapes.c \
src/get_mstr_w.c \
src/get_mstr_h.c \
src/get_tetr_height.c \
src/get_tetr_width.c \
src/wipe_mstr.c \
src/options2square.c \
src/get_mlst_h.c \
src/print_node_info.c \
src/get_mlst_w.c \
src/opts_lst_to_square_str.c \
src/compose_mstr_of_opts_from_shapes_str.c \
src/get_n_of_opts_in_mlst.c \
src/print_all_nodes_mlst.c \
src/choose_option.c \
src/cover_option_of_node.c \
src/delete_node.c \
src/update_mlst_status.c \
src/get_first_block_num_in_option.c \
src/get_last_block_num_in_option.c \
src/insert_node.c \
src/unchoose_option.c \
src/uncover_item.c \
src/uncover_option_of_node.c \
src/gbo.c \
src/get_next_submatrix_ptr.c \
src/skip_to_next_unempty_opt.c \
src/cover_item.c

OBJS = \
	get_number_of_options_for_tetrimino.o \
	get_submatrix_for_tetr.o \
	get_number_of_items.o \
	print_mstr.o \
	get_tetr_sign.o \
	get_new_node.o \
	get_matrix_of_dots.o \
	get_mlst_from_mstr.o \
	print_mlst.o \
	get_tetr_shape_type.o \
	join_matrices_str.o \
	check_input_and_get_str_of_shapes.o \
	get_mstr_w.o \
	get_mstr_h.o \
	get_tetr_height.o \
	get_tetr_width.o \
	wipe_mstr.o \
	options2square.o \
	get_mlst_h.o \
	print_node_info.o \
	get_mlst_w.o \
	opts_lst_to_square_str.o \
	compose_mstr_of_opts_from_shapes_str.o \
	get_n_of_opts_in_mlst.o \
	print_all_nodes_mlst.o \
	choose_option.o \
	cover_option_of_node.o \
	delete_node.o \
	update_mlst_status.o \
	get_first_block_num_in_option.o \
	get_last_block_num_in_option.o \
	insert_node.o \
	unchoose_option.o \
	uncover_item.o \
	uncover_option_of_node.o \
	gbo.o \
	get_next_submatrix_ptr.o \
	skip_to_next_unempty_opt.o \
	cover_item.o


all: $(EXEC)


$(EXEC): $(OBJS)
	@gcc $(CFLAGS) -o $(EXEC) $(OBJS) $(MAIN) -I . -L "libft/" -lft

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(EXEC)

re: fclean all

test: re
	clear
	./$(EXEC) $(TEST)
