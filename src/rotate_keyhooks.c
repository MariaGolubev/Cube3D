/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_keyhooks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 11:39:26 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 14:24:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_u64	rotate_right_keyhok(t_app *app, t_key_action action)
{
	t_kstate	*keys_state;

	keys_state = app_source_get(app, "keys_state");
	if (action == KEY_PRESS)
		keys_state->rotate_right = true;
	else if (action == KEY_RELEASE)
		keys_state->rotate_right = false;
	return (EVENT_NONE_MSK);
}

static t_u64	rotate_left_keyhook(t_app *app, t_key_action action)
{
	t_kstate	*keys_state;

	keys_state = app_source_get(app, "keys_state");
	if (action == KEY_PRESS)
		keys_state->rotate_left = true;
	else if (action == KEY_RELEASE)
		keys_state->rotate_left = false;
	return (EVENT_NONE_MSK);
}

void	set_rotate_keyhooks(t_app *app)
{
	app_keyhook_add(app, MLX_KEY_RIGHT, rotate_right_keyhok);
	app_keyhook_add(app, MLX_KEY_LEFT, rotate_left_keyhook);
}
