/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   storage.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 20:12:04 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 11:19:59 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_H
# define STORAGE_H
# include "hashtable.h"

typedef void	(*t_del_fn)(void *);

typedef struct s_source
{
	void		*ptr;
	t_del_fn	del;
}				t_source;

typedef struct s_storage
{
	t_hashtable	sources;
}				t_storage;

void			source_destroy(void *ptr);

int				storage_init(t_storage *storage, t_u16 size);
void			storage_destroy(t_storage *storage);

int				storage_add(t_storage *storage, const char *key, void *source,
					t_del_fn del);
void			*storage_get(t_storage *storage, const char *key);
#endif
