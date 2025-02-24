/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 20:44:34 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "libft.h"
# include "stdbool.h"
# include "types.h"
# include <stdlib.h>

typedef struct s_hash_node
{
	t_u64		key;
	void		*value;
}				t_hash_node;

typedef struct s_hashtable
{
	t_hash_node	*array;
	t_u64		*index;
	t_u16		len;
	t_u16		bucket_count;
	bool		is_allocated;
}				t_hashtable;

typedef void	(*t_delfn)(void *);

void			hash_node_destroy(t_hash_node *node, t_delfn fn);

int				hashtable_init(t_hashtable *table, t_u16 bucket_count);
t_hashtable		*hashtable_new(t_u16 bucket_count);
void			hashtable_destroy(t_hashtable *table, t_delfn fn);
;
int				hashtable_insert(t_hashtable *table, t_u64 key, void *value,
					t_delfn fn);
void			*hashtable_search(t_hashtable *table, t_u64 key);

#endif
