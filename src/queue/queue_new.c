/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:39:54 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/03 11:40:22 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*queue_new(size_t size)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	if (queue_init(queue, size) != 0)
	{
		free(queue);
		return (NULL);
	}
	queue->is_allocated = true;
	return (queue);
}
