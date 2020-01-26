.PHONY: all re clean fclean test

MAIN = main.c

TEST = ../tests/test

CFLAGS = -Wall -Werror -Wextra

EXEC = fillit

SRCS = \
	get_number_of_options_for_tetrimino.c \
	get_submatrix_for_tetr.c \
	get_number_of_items.c \
	print_matrix_str.c \
	get_tetr_sign.c \
	get_new_node.c \
	get_matrix_of_dots.c \
	get_mlst_from_mstr.c \
	print_matrix_lst_conseq.c \
	get_tetr_shape_type.c \
	join_matrices_str.c \
	check_input_and_get_str_of_shapes.c \
	get_mstr_w.c \
	get_mstr_h.c \
	get_tetr_height.c \
	get_tetr_width.c \
	wipe_mstr.c \
	options2square.c \
	get_mlst_h.c \
	print_node_info.c \
	get_mlst_w.c \
	opts_lst_to_square_str.c \
	compose_mstr_of_opts_from_shapes_str.c \
	get_n_of_opts_in_mlst.c \
	print_all_nodes_mlst.c \
	choose_option.c \
	cover_option_of_node.c \
	delete_node.c \
	update_mlst_status.c \
	get_first_block_num_in_option.c \
	get_last_block_num_in_option.c \
	insert_node.c \
	unchoose_option.c \
	uncover_item_of_node.c \
	uncover_option_of_node.c \
	gbo.c \
	get_next_submatrix_ptr.c \
	skip_to_next_unempty_opt.c \
	cover_item_of_node.c

OBJS = \
	get_number_of_options_for_tetrimino.o \
	get_submatrix_for_tetr.o \
	get_number_of_items.o \
	print_matrix_str.o \
	get_tetr_sign.o \
	get_new_node.o \
	get_matrix_of_dots.o \
	get_mlst_from_mstr.o \
	print_matrix_lst_conseq.o \
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
	uncover_item_of_node.o \
	uncover_option_of_node.o \
	gbo.o \
	get_next_submatrix_ptr.o \
	skip_to_next_unempty_opt.o \
	cover_item_of_node.o


all: $(EXEC)


$(EXEC): $(OBJS)
	@gcc $(CFLAGS) -o $(EXEC) $(OBJS) $(MAIN) -I . -L "./../libft/" -lft -lm

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(EXEC)

re: fclean all

test: re
	clear
	./$(EXEC) $(TEST) #> logfile && vim logfile
