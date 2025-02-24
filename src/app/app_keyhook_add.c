/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_keyhook_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:33:04 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/13 14:36:55 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_keyhook_add(t_app *app, t_u64 keycode, t_keyhook_fn fn)
{
	if (hashtable_insert(&app->keyhooks, keycode, fn, NULL) != 0)
	{
		ft_putendl_fd("Error\nAdd keyhook error", 2);
		app_destroy(app);
		exit(1);
	}
}
