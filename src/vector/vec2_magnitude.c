/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2_magnitude.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 18:59:51 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 11:17:33 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_f64	vec2_magnitude(t_vec2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}
