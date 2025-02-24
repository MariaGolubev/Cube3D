/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_image_new.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 11:57:03 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/11 19:50:02 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_image	*app_image_new(t_app *app, t_i32 width, t_i32 height)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (image == NULL)
	{
		app_destroy(app);
		ft_putendl_fd("Error\nMlx Image error", 2);
		exit(1);
	}
	image->image = mlx_new_image(app->mlx, width, height);
	if (image->image == NULL)
	{
		free(image);
		app_destroy(app);
		ft_putendl_fd("Error\nMlx Image error", 2);
		exit(1);
	}
	image->mlx = app->mlx;
	return (image);
}
