/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable_new.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 20:55:04 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/20 21:10:46 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable	*hashtable_new(t_u16 bucket_count)
{
	t_hashtable	*table;

	table = (t_hashtable *)malloc(sizeof(t_hashtable));
	if (table == NULL)
		return (NULL);
	hashtable_init(table, bucket_count);
	table->is_allocated = true;
	return (table);
}
