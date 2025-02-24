/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_image_from_texture.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 11:58:58 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/13 13:07:54 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_image	*app_image_from_texture(t_app *app, t_texture *texture)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (image == NULL)
		return (NULL);
	image->image = mlx_texture_to_image(app->mlx, texture);
	if (image->image == NULL)
	{
		ft_putendl_fd("Error\nMlx texture to image error", 2);
		free(image);
		app_destroy(app);
		exit(1);
	}
	image->mlx = app->mlx;
	return (image);
}
