/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_dequeue.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 12:03:32 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/03 13:49:48 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*queue_dequeue(t_queue *queue)
{
	void	*data;

	if (queue_isempty(queue) == true)
		return (NULL);
	data = queue->data[queue->front];
	queue->data[queue->front] = NULL;
	queue->front = (queue->front + 1) % queue->size;
	queue->count--;
	return (data);
}
