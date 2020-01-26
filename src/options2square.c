#include "fillit.h"

int	get_a(int a);

char	**options2square(char **opts)
{
	int	a;
	int	i;
	int	l;
	int	i2;
	int	l2;
	char	**square;

	i2 = 0;
	l2 = 0;
	a = 0;
	i = 0;
	l = 0;
	square = NULL;
	square = (char**)malloc( sizeof(char*) * (a + 1));
	a = get_mstr_w(opts);
	a = get_a(a);
	while(square[i][l])
	{
		while(i <= a)
		{
			square[i][l] = '.';
			i++;
		}
		l++;
		i = 0;
	}
	i = 0;
	l = 0;
	while(opts[i][l] != '\0')
	{
		while(opts[i][l] != '\n')
		{
			if(opts[i][l] >= 'A' && opts[i][l] <= 'Z')
			{
				square[i2][l2] = opts[i][l];
				i++;
				i2++;
			}
			if (i2 == a)
			{
				i2 = 0;
				l2++;
			}
			else
			{
				i++;
				i2++;
				l2++;
			}
		}
		l++;
		i = 0;
	}
	return (square);
}

int	get_a(int a)
{
	int	i;

	i = 1;
	while (a != i)
	{
		i++;
		i = i * i;
	}
	return (i);
}
