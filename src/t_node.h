/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 06:22:49 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/01 06:23:34 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NODE_H
# define T_NODE_H

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

#endif
