/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_system_add.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:35:39 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/13 14:37:41 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_system_add(t_app *cube, t_system_fn fn, t_u64 event_mask)
{
	if (sysmanager_add(&cube->sysmanager, (t_sys_fn)fn, event_mask) != 0)
	{
		ft_putendl_fd("Error\nAdd system error", 2);
		app_destroy(cube);
		exit(1);
	}
}
