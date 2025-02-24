/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_peek.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:43:36 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/03 11:44:01 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*queue_peek(t_queue *queue)
{
	if (queue_isempty(queue) == false)
		return (queue->data[queue->front]);
	return (NULL);
}
