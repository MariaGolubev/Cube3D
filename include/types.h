/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 20:44:45 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/08 17:42:50 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923
# endif

typedef unsigned char		t_u8;
typedef unsigned int		t_u32;
typedef unsigned short		t_u16;
typedef unsigned long		t_u64;
typedef unsigned long long	t_u128;

typedef char				t_i8;
typedef int					t_i32;
typedef short				t_i16;
typedef long				t_i64;
typedef long long			t_i128;

typedef float				t_f32;
typedef double				t_f64;
typedef long double			t_f128;

#endif
