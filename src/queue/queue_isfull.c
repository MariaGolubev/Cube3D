/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_isfull.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:42:36 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/03 11:59:21 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

bool	queue_isfull(t_queue *queue)
{
	if (queue->count == queue->size)
		return (true);
	return (false);
}
