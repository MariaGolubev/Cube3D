/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 18:59:40 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 17:39:39 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec2(t_f64 x, t_f64 y)
{
	t_vec2	result;

	result.x = x;
	result.y = y;
	return (result);
}

t_vec2	*vec2_new(t_f64 x, t_f64 y)
{
	t_vec2	*result;

	result = (t_vec2 *)malloc(sizeof(t_vec2));
	if (result == NULL)
		return (NULL);
	result->x = x;
	result->y = y;
	return (result);
}

int	vec2_new_into(t_vec2 **vec, t_f64 x, t_f64 y)
{
	*vec = vec2_new(x, y);
	if (*vec == NULL)
		return (1);
	return (0);
}
