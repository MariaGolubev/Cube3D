/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2_scale.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 18:59:46 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec2_scale(t_vec2 a, t_f64 scalar)
{
	t_vec2	result;

	result.x = a.x * scalar;
	result.y = a.y * scalar;
	return (result);
}
