/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 16:47:42 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 13:23:03 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include "MLX42/MLX42.h"
# include "hashtable.h"
# include "storage.h"
# include "sysmanager.h"
# include <stdlib.h>

# define DEFAULT_WIDTH 1920
# define DEFAULT_HEIGHT 1080

# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440

typedef struct s_app
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	t_hashtable			keyhooks;
	t_storage			storage;
	t_sysmanager		sysmanager;
}						t_app;

typedef enum e_key_action
{
	KEY_RELEASE = 0,
	KEY_PRESS = 1,
	KEY_REPEAT = 2,
}						t_key_action;

typedef enum e_cursor_mode
{
	CURSOR_NORMAL = 0x00034001,
	CURSOR_HIDDEN = 0x00034002,
	CURSOR_DISABLED = 0x00034003,
}						t_cursor_mode;

typedef struct s_image
{
	mlx_image_t			*image;
	mlx_t				*mlx;
}						t_image;

typedef mlx_texture_t	t_texture;
typedef t_u64			(*t_keyhook_fn)(t_app *cube, t_key_action action);
typedef t_u64			(*t_system_fn)(t_app *cube);

void					image_destroy(t_image *image);
int						app_init(t_app *cube, t_i32 w, t_i32 h,
							const char *title);
void					app_set_hooks(t_app *cube);
void					app_destroy(t_app *cube);
void					app_run(t_app *cube);
t_u32					app_get_width(t_app *cube);
t_u32					app_get_height(t_app *cube);
t_f64					app_get_delta_time(t_app *cube);

void					app_keyhook_add(t_app *cube, t_u64 keycode,
							t_keyhook_fn fn);
void					app_system_add(t_app *cube, t_system_fn fn,
							t_u64 event_mask);
void					app_source_add(t_app *cube, const char *key,
							void *source, void (*del)(void *));
void					*app_source_get(t_app *cube, const char *key);
void					app_event_add(t_app *cube, t_u64 event_mask);
void					app_set_cursor_mode(t_app *cube, t_cursor_mode mode);

t_image					*app_image_new(t_app *cube, t_i32 width, t_i32 height);
t_image					*app_image_from_texture(t_app *cube,
							t_texture *texture);
void					app_image_to_window(t_app *app, t_image *image, t_u32 x,
							t_u32 y);

#endif
