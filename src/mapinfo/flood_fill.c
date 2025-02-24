/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/05 09:27:28 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/24 20:07:00 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mapinfo.h"

static int	init_currend(t_queue *queue, t_map *map, int *visited, t_vec2 pos)
{
	t_vec2	*start;

	start = vec2_new(pos.x, pos.y);
	if (start == NULL)
	{
		queue_destroy(queue, free);
		free(visited);
		return (MAPINFO_MALLOC_ERROR);
	}
	queue_enqueue(queue, start);
	visited[(int)pos.y * map->width + (int)pos.x] = 1;
	return (MAPINFO_SUCCESS);
}

static int	set_neighbours(t_vec2 *neighbours, t_queue *queue)
{
	t_vec2	*current;

	if (queue_isempty(queue))
		return (MAPINFO_SUCCESS);
	current = queue_dequeue(queue);
	if (current == NULL)
		return (MAPINFO_MALLOC_ERROR);
	neighbours[0] = vec2_add(*current, vec2(0, 1));
	neighbours[1] = vec2_add(*current, vec2(0, -1));
	neighbours[2] = vec2_add(*current, vec2(1, 0));
	neighbours[3] = vec2_add(*current, vec2(-1, 0));
	free(current);
	return (MAPINFO_SUCCESS);
}

static int	process_neighbours(t_queue *queue, t_map *m, int *vis,
		t_vec2 *neighbours)
{
	int		i;
	t_i32	nx;
	t_i32	ny;
	t_vec2	*next;

	i = 4;
	while (i--)
	{
		nx = neighbours[i].x;
		ny = neighbours[i].y;
		if (nx < 0 || ny < 0 || nx == (t_i32)m->width || ny == (t_i32)m->height)
			continue ;
		if (map_get(m, nx, ny) == 0 && vis[ny * m->width + nx] == 0)
		{
			if (nx == 0 || ny == 0 || nx == (t_i32)m->width - 1
				|| ny == (t_i32)m->height - 1)
				return (MAPINFO_MAP_FLOOD_FILL_ERROR);
			if (vec2_new_into(&next, nx, ny) != 0)
				return (MAPINFO_MALLOC_ERROR);
			if (queue_enqueue(queue, next) != 0)
				return (free(next), MAPINFO_MALLOC_ERROR);
			vis[ny * m->width + nx] = 1;
		}
	}
	return (MAPINFO_SUCCESS);
}

static int	destroy_and_return(t_queue *queue, int *visited, int status)
{
	queue_destroy(queue, free);
	free(visited);
	return (status);
}

int	flood_fill(t_map *map, t_vec2 pos)
{
	t_queue	queue;
	int		*visited;
	t_vec2	neighbours[4];
	int		status;

	status = MAPINFO_SUCCESS;
	if (pos.x < 0 || pos.y < 0 || pos.x >= map->width || pos.y >= map->height)
		return (MAPINFO_MAP_FLOOD_FILL_ERROR);
	if (queue_init(&queue, map->width
			* map->height) != 0)
		return (MAPINFO_MALLOC_ERROR);
	visited = ft_calloc(map->width * map->height, sizeof(int));
	if (visited == NULL)
		return (queue_destroy(&queue, free), MAPINFO_MALLOC_ERROR);
	if (init_currend(&queue, map, visited, pos) != MAPINFO_SUCCESS)
		return (destroy_and_return(&queue, visited, MAPINFO_MALLOC_ERROR));
	while (!queue_isempty(&queue))
	{
		status = set_neighbours(neighbours, &queue);
		if (status != MAPINFO_SUCCESS)
			break ;
		status = process_neighbours(&queue, map, visited, neighbours);
		if (status != MAPINFO_SUCCESS)
			break ;
	}
	return (destroy_and_return(&queue, visited, status));
}
