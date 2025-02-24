/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   storage_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 20:28:18 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/21 20:29:17 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "storage.h"

int	storage_init(t_storage *storage, t_u16 size)
{
	return (hashtable_init(&storage->sources, size));
}
