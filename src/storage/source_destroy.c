/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   source_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 22:02:51 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/07 13:58:31 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "storage.h"

void	source_destroy(void *ptr)
{
	t_source	*source;

	source = ptr;
	if (source->del)
		source->del(source->ptr);
	free(source);
}
