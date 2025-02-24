/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 18:54:32 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 17:39:55 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "types.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_vec2
{
	t_f64	x;
	t_f64	y;
}			t_vec2;

t_vec2		vec2(t_f64 x, t_f64 y);
t_vec2		*vec2_new(t_f64 x, t_f64 y);
int			vec2_new_into(t_vec2 **vec, t_f64 x, t_f64 y);
t_vec2		vec2_add(t_vec2 a, t_vec2 b);
t_vec2		vec2_sub(t_vec2 a, t_vec2 b);
t_vec2		vec2_scale(t_vec2 a, t_f64 scalar);
t_f64		vec2_dot(t_vec2 a, t_vec2 b);
t_f64		vec2_cross(t_vec2 a, t_vec2 b);
t_f64		vec2_magnitude(t_vec2 a);
t_vec2		vec2_normalize(t_vec2 a);
t_f64		vec2_length(t_vec2 a);
t_f64		vec2_distance(t_vec2 a, t_vec2 b);
t_vec2		vec2_rotate(t_vec2 vec, t_f64 angle);

#endif
