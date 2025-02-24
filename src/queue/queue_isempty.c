/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_isempty.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:41:44 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/03 11:59:10 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

bool	queue_isempty(t_queue *queue)
{
	if (queue->count == 0)
		return (true);
	return (false);
}
