#include "fillit.h"

void	print_mstr(char **matrix)
{
    int	i;
	int	n_of_items;
	int	sq_side;

	n_of_items = get_mstr_w(matrix);

    i = 0;
	printf("    ");
	while (i < n_of_items)
	{
		/* printf("%1d", i / sq_side); */
		printf("%1d", i / 100);
		i += 1;
	}
	printf("\n");



	i = 0;
	printf("    ");
	while (i < n_of_items)
	{
		/* printf("%1d", (i / sq_side) / 10); */
		printf("%1d", i / 10);
		i += 1;
	}
	printf("\n");



	i = 0;
	printf("    ");
	while (i < n_of_items)
	{
		/* printf("%1d", i % sq_side); */
		printf("%1d", i % 10);
		i += 1;
	}
	printf("\n");



	i = 0;
	while (matrix[i])
	{
		printf("%2d: %s\n", \
			   i, matrix[i]);
		i++;
    }

	printf("=====================\n");
}
