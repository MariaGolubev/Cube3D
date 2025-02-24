/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:28:56 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "libft.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_queue
{
	void	**data;
	size_t	front;
	size_t	rear;
	size_t	size;
	size_t	count;
	bool	is_allocated;
}			t_queue;

int			queue_init(t_queue *queue, size_t size);
t_queue		*queue_new(size_t size);
void		queue_destroy(t_queue *queue, void (*del)(void *));
int			queue_enqueue(t_queue *queue, void *data);
void		*queue_dequeue(t_queue *queue);
void		*queue_peek(t_queue *queue);
bool		queue_isempty(t_queue *queue);
bool		queue_isfull(t_queue *queue);

#endif
