/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_enqueue.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:44:53 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/03 12:04:54 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	queue_enqueue(t_queue *queue, void *data)
{
	if (queue_isfull(queue) == true)
		return (1);
	queue->rear = (queue->rear + 1) % queue->size;
	queue->data[queue->rear] = data;
	queue->count++;
	return (0);
}
