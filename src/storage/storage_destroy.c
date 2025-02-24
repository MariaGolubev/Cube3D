/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   storage_destroy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 20:22:23 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/21 22:03:03 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "storage.h"

void	storage_destroy(t_storage *storage)
{
	hashtable_destroy(&storage->sources, source_destroy);
}
