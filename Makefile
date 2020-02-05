#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 00:07:33 by slisandr          #+#    #+#              #
#    Updated: 2020/02/05 02:22:49 by slisandr         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all re clean fclean test memcheck libft

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

TEST = test

CFLAGS = -Wall -Werror -Wextra

NAME = fillit

SRC_DIR = src
OBJ_DIR = obj

SRC_RAW = \
	get_number_of_options_for_tetrimino.c \
	get_submatrix_for_tetr.c \
	get_number_of_items.c \
	get_tetr_sign.c \
	get_new_node.c \
	get_matrix_of_dots.c \
	get_mlst_from_mstr.c \
	get_tetr_shape_type.c \
	join_matrices_str.c \
	check_input_and_get_str_of_shapes.c \
	get_mstr_w.c \
	get_mstr_h.c \
	get_tetr_height.c \
	get_tetr_width.c \
	wipe_mstr.c \
	get_mlst_h.c \
	get_mlst_w.c \
	opts_lst_to_square_str.c \
	get_opts_mstr.c \
	get_n_of_opts_in_mlst.c \
	choose_option.c \
	cover_option_of_node.c \
	delete_node.c \
	update_mlst_status.c \
	insert_node.c \
	unchoose_option.c \
	uncover_item.c \
	uncover_option_of_node.c \
	gbo.c \
	get_ptr.c \
	skip.c \
	print_mstr.c \
	get_num_of_blocks_in_mstr.c \
	create_vert_connections_in_mlst.c \
	connect_nodes_vert.c \
	translate_blocks_and_spacers.c \
	wipe_mlst.c \
	cover_item.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))


all: $(NAME)

$(NAME): libft $(OBJ_DIR) $(OBJ)
	@ echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@ gcc $(CFLAGS) -o $(NAME) $(OBJ) $(MAIN) -I "includes/" -I "libft/includes/" -L "libft/" -lft
	@ echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
libft:
	@ make -C libft/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ gcc $(FLAGS) -I "includes/" -I "libft/includes/" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ echo "$(NAME): $(GREEN)$(OBJ_DIR) folder was created$(RESET)"


clean:
	@ rm -rf $(OBJ_DIR)
	@ echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@ echo "$(NAME): $(RED)$(OBJ_DIR) folder was deleted$(RESET)"
	@ make -C libft/ clean
fclean: clean
	@ rm -rf $(NAME)
	@ echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@ make -C libft/ fclean
re: fclean all


test: re
	clear
	./$(NAME) $(TEST)

memcheck: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) $(TEST)
	vim valgrind-out.txt
