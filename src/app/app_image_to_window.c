/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_image_to_window.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/29 18:22:27 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/13 14:36:03 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_image_to_window(t_app *app, t_image *image, t_u32 x, t_u32 y)
{
	if (mlx_image_to_window(app->mlx, image->image, x, y) == -1)
	{
		ft_putendl_fd("Error\nMlx tmage to window error", 2);
		app_destroy(app);
		exit(1);
	}
}
