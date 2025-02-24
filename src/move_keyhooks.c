/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_keyhooks.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 11:37:25 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 14:24:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_u64	move_forward_keyhook(t_app *app, t_key_action action)
{
	t_kstate	*keys_state;

	keys_state = app_source_get(app, "keys_state");
	if (action == KEY_PRESS)
		keys_state->move_forward = true;
	else if (action == KEY_RELEASE)
		keys_state->move_forward = false;
	return (EVENT_NONE_MSK);
}

static t_u64	move_back_keyhook(t_app *app, t_key_action action)
{
	t_kstate	*keys_state;

	keys_state = app_source_get(app, "keys_state");
	if (action == KEY_PRESS)
		keys_state->move_back = true;
	else if (action == KEY_RELEASE)
		keys_state->move_back = false;
	return (EVENT_NONE_MSK);
}

static t_u64	move_right_keyhook(t_app *app, t_key_action action)
{
	t_kstate	*keys_state;

	keys_state = app_source_get(app, "keys_state");
	if (action == KEY_PRESS)
		keys_state->move_right = true;
	else if (action == KEY_RELEASE)
		keys_state->move_right = false;
	return (EVENT_NONE_MSK);
}

static t_u64	move_left_keyhook(t_app *app, t_key_action action)
{
	t_kstate	*keys_state;

	keys_state = app_source_get(app, "keys_state");
	if (action == KEY_PRESS)
		keys_state->move_left = true;
	else if (action == KEY_RELEASE)
		keys_state->move_left = false;
	return (EVENT_NONE_MSK);
}

void	set_move_keyhooks(t_app *app)
{
	app_keyhook_add(app, MLX_KEY_W, move_forward_keyhook);
	app_keyhook_add(app, MLX_KEY_S, move_back_keyhook);
	app_keyhook_add(app, MLX_KEY_D, move_right_keyhook);
	app_keyhook_add(app, MLX_KEY_A, move_left_keyhook);
}
