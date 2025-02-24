/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 11:00:15 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 13:54:21 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "app.h"
# include "camera.h"
# include "dda_raycast.h"
# include "mapinfo.h"
# include "types.h"
# include "vector.h"
# include <fcntl.h>
# include <math.h>

# define RAYCAST_SYS_MAX_ITER 50

# define ROTATE_SPEED 2.0
# define MOUSE_ROTATE_SPEED 0.15
# define MOVE_SPEED 5.0

# define N_TEXTURE "n_texture"
# define S_TEXTURE "s_texture"
# define W_TEXTURE "w_texture"
# define E_TEXTURE "e_texture"

# define EVENT_DRAW_MSK 1

typedef struct s_keys_state
{
	bool	move_forward;
	bool	move_back;
	bool	move_left;
	bool	move_right;
	bool	rotate_left;
	bool	rotate_right;

}			t_kstate;

void		set_move_keyhooks(t_app *app);
void		set_rotate_keyhooks(t_app *app);

void		mapinfo_from_path(t_app *app, const char *path);

// Draw cf sys
t_u64		draw_cf_system(t_app *app);

// Minimap sys
t_u64		minimap_system(t_app *app);

// Misc keyhooks
t_u64		exit_keyhook(t_app *app, t_key_action action);
t_u64		mouse_focused_keyhook(t_app *app, t_key_action action);

// Movement sys

t_u64		mouse_rotate_system(t_app *app);
t_u64		move_system(t_app *app);

// Raycast sys

t_u64		raycast_system(t_app *app);

// Resize sys
t_u64		resize_system(t_app *app);

// Utils
t_u32		from_rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);
t_u32		mix(t_u32 color1, t_u32 color2, t_f64 ratio);
t_i32		imax(t_i32 a, t_i32 b);
t_i32		imin(t_i32 a, t_i32 b);
t_u32		texture_get_pixel(mlx_texture_t *texture, t_f64 offset_x,
				t_f64 offset_y);
int			check_path(const char *path, const char *ext);
void		exiterr(t_app *app, const char *msg, bool sys, int status);

#endif
