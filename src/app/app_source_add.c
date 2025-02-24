/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_source_add.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:34:54 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/13 14:37:33 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_source_add(t_app *app, const char *key, void *source,
		void (*del)(void *))
{
	if (source == NULL || storage_add(&app->storage, key, source, del) != 0)
	{
		ft_putendl_fd("Error\nAdd source error", 2);
		app_destroy(app);
		exit(1);
	}
}
