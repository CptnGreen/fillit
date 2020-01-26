#include "fillit.h"

size_t		get_num_of_blocks_in_mstr(char **m);
void		create_vert_connections_in_mlst(t_node **m_lst);
void		connect_nodes_vert(t_node *down, t_node *up);
void		make_super_connections(t_node **m_lst);
void		connect_headers_to_first_nodes(t_node **m_lst);
void		connect_block_nodes(t_node **m_lst);
void		translate_upper_row(t_node **m_lst, size_t w);
void		translate_blocks_and_spacers(\
            t_node **m_lst, char **m_str, size_t w, size_t h, size_t n);
void		remember_inferior_nodes(t_node **m_lst);

t_node	**get_mlst_from_mstr(char **m_str)
{
    t_node	**m_lst;
    size_t	h;
    size_t	w;
    size_t	n;

    w = get_mstr_w(m_str);
    h = get_mstr_h(m_str);
    n = get_num_of_blocks_in_mstr(m_str);
    m_lst = (t_node **)malloc((h + w + n + 3) * sizeof(t_node *));
    translate_upper_row(m_lst, w);
    translate_blocks_and_spacers(m_lst, m_str, w, h, n);
    create_vert_connections_in_mlst(m_lst);
    return (m_lst);
}

void			translate_upper_row(t_node **m_lst, size_t w)
{
    int			i;
    size_t		n;

    m_lst[0] = get_new_node(0, 'z', 'z', -1, -1);
    i = 1;
    while (i < (w + 1))
    {
        m_lst[i] = get_new_node(\
            i, 'h', 'H'/* (i - 1 >= 10) ? ('h') : ((i - 1) + '0') */, -1, i - 1);
        m_lst[i - 1]->r = m_lst[i];
        m_lst[i]->l = m_lst[i - 1];
        i++;
    }
    m_lst[i - 1]->r = m_lst[0];
    m_lst[0]->l = m_lst[i - 1];
}

void			translate_blocks_and_spacers(\
    t_node **m_lst, char **m_str, size_t w, size_t h, size_t n)
{
    int			i;
    int			x;
    int			y;
	t_node		*spacer;

    /*
    ** First spacer:
    */
    i = w + 1;
    x = 0;
    y = -1;
    m_lst[i] = get_new_node(i, 's', 's', 0, -1);
	spacer = m_lst[i];
	spacer->u = m_lst[0];
	m_lst[0]->d = spacer;
    i++;
    while (i < (h + w + n + 2))
    {
        y++;
        if (m_str[x][y] >= 'A' && m_str[x][y] <= 'Z')
        {
            m_lst[i] = get_new_node(i, 'b', m_str[x][y], x, y);
			m_lst[i]->l = spacer;
			if (spacer->r == NULL)
				spacer->r = m_lst[i];
			spacer->c = m_str[x][y];
            i++;
        }
        else if (m_str[x][y] == '\0')
        {
            m_lst[i] = get_new_node(i, 's', 's', x + 1, -1);
			m_lst[i]->u = spacer;
			spacer->d = m_lst[i];
			spacer = m_lst[i];
			m_lst[i - 1]->r = m_lst[i - 2]->r = m_lst[i - 3]->r = m_lst[i - 4]->r = spacer;
			spacer->l = m_lst[i - 1];
            i++;
            x++;
            y = -1;
        }
    }
    m_lst[i] = NULL;
	m_lst[i - 1]->d = m_lst[0];
	m_lst[0]->u = m_lst[i - 1];
	m_lst[i - 1]->c = '$';
}

void		create_vert_connections_in_mlst(t_node **m_lst)
{
    connect_headers_to_first_nodes(m_lst);
    /* printf("Step 1:\n===========\n"); */
    /* print_node_info(m_lst[17]); */

    connect_block_nodes(m_lst);
    /* printf("Step 2:\n===========\n"); */
    /* print_node_info(m_lst[17]); */

    make_super_connections(m_lst);
    /* printf("Step 3:\n===========\n"); */
    /* print_node_info(m_lst[17]); */

	remember_inferior_nodes(m_lst);
}

void		remember_inferior_nodes(t_node **m_lst)
{
	t_node	*cur;

	cur = m_lst[0]->r;
	while (cur->role != 'z')
	{
		cur->s = cur->u;
		cur = cur->r;
	}
}


void		connect_headers_to_first_nodes(t_node **m_lst)
{
    int			n;
    int			item;
    int			i;

    n = 1;
    item = 0;
    while (m_lst[n]->role == 'h')
    {
        i = n + 1;
        while (m_lst[i])
        {
            if (m_lst[i]->y == item)
            {
                connect_nodes_vert(m_lst[i], m_lst[n]);
                break ;
            }
            i += 1;
        }
        /* printf("Header #%d connected:\n", n); */
        /* print_node_info(m_lst[n]); */
        n += 1;
        item += 1;
    }
}

void		connect_block_nodes(t_node **m_lst)
{
    int			n;
    int			item;
    int			i;
    t_node		*prev;
    t_node		*cur;

    n = 1;
    item = 0;
    while (m_lst[n]->role == 'h')
    {
        if (m_lst[n]->d)
        {
            prev = m_lst[n]->d;
            i = prev->n + 1;
            while (m_lst[i])
            {
                if (m_lst[i]->y == item)
                {
                    connect_nodes_vert(m_lst[i], prev);
                    prev = m_lst[i];
                }
                i += 1;
            }
            connect_nodes_vert(m_lst[n], prev);
            n++;
            item += 1;
        }
        else
        {
            connect_nodes_vert(m_lst[n], m_lst[n]);
            n++;
            item += 1;
        }
    }
}

void		make_super_connections(t_node **m_lst)
{
    int		i;

    i = 0;
    while (m_lst[i])
    {
		/* m_lst[i]->s = m_lst[m_lst[i]->y + 1]; */
		if (m_lst[i]->role == 'b' || m_lst[i]->role == 'h')
			m_lst[i]->s = m_lst[i]->u;
		else if (m_lst[i]->role == 'z' || m_lst[i]->role == 's')
			m_lst[i]->s = m_lst[m_lst[i]->y + 1];
		i += 1;
    }
}

void		connect_nodes_vert(t_node *down, t_node *up)
{
    up->d = down;
    down->u = up;
}

size_t	get_num_of_blocks_in_mstr(char **m)
{
    size_t	num;
    int			i;
    int			j;

    num = 0;
    i = 0;
    while (m[i])
    {
        j = 0;
        while (m[i][j])
        {
            if (m[i][j] != '.')
                num++;
            j++;
        }
        i++;
    }
    return (num);
}
