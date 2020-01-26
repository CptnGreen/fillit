#include "fillit.h"

char	**join_matrices_str(char **m1, char **m2)
{
	char		**m;
	unsigned int	m1_h;
	unsigned int	m2_h;
	int		i;
	int		j;

	printf("After joining matrices:\n");
	if (!m1 || !m2)
		return (NULL);
	m1_h = get_mstr_h(m1);
	m2_h = get_mstr_h(m2);
	printf("join: m1_h = %d, m2_h = %d\n", m1_h, m2_h);
	m = (char **)malloc((m1_h + m2_h + 1) * sizeof(char *));
	i = j = -1;
	while (++i < m1_h)
		m[i] = ft_strdup(m1[i]);
	wipe_mstr(m1);
	while (++j < m2_h)
		m[i + j] = ft_strdup(m2[j]);
	m[i + j] = NULL;
	wipe_mstr(m2);
	print_matrix_str(m);
	return (m);
}
