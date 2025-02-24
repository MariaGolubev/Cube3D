/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 20:13:45 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec2_rotate(t_vec2 vec, t_f64 angle)
{
	t_vec2	result;

	result.x = vec.x * cos(angle) - vec.y * sin(angle);
	result.y = vec.x * sin(angle) + vec.y * cos(angle);
	return (result);
}
