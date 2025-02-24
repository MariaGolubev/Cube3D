/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_destroy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 11:56:07 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 14:05:22 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	image_destroy(t_image *image)
{
	mlx_delete_image(image->mlx, image->image);
	free(image);
}
