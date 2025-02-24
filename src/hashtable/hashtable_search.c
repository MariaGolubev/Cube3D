/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable_search.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 13:46:24 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/07 13:46:24 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	*hashtable_search(t_hashtable *table, t_u64 key)
{
	t_u64	hash;
	t_u16	i;

	i = 0;
	while (i < table->len)
	{
		hash = (key + i * i) % table->bucket_count;
		if (table->array[hash].value == NULL)
			return (NULL);
		if (table->array[hash].key == key)
			return (table->array[hash].value);
		i++;
	}
	return (NULL);
}
