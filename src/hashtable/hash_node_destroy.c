/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_node_destroy.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 20:45:06 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/20 21:43:28 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	hash_node_destroy(t_hash_node *node, t_delfn fn)
{
	node->key = 0;
	if (fn != NULL)
		fn(node->value);
	node->value = NULL;
}
