/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 20:01:28 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_f64	vec2_distance(t_vec2 a, t_vec2 b)
{
	t_f64	distance;

	distance = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	return (distance);
}
