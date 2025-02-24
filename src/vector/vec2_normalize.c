/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2_normalize.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 18:59:48 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec2	vec2_normalize(t_vec2 a)
{
	t_vec2	result;
	t_f64	magnitude;

	magnitude = vec2_magnitude(a);
	result.x = a.x / magnitude;
	result.y = a.y / magnitude;
	return (result);
}
