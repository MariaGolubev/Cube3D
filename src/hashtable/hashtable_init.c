/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 20:52:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/21 10:51:26 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

int	hashtable_init(t_hashtable *table, t_u16 bucket_count)
{
	table->array = (t_hash_node *)ft_calloc(bucket_count, sizeof(t_hash_node));
	if (!table->array)
		return (1);
	table->index = (t_u64 *)ft_calloc(bucket_count, sizeof(t_u64));
	if (!table->index)
		return (free(table->array), 1);
	table->len = 0;
	table->bucket_count = bucket_count;
	table->is_allocated = false;
	return (0);
}
