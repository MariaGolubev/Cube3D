/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_get.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 11:43:19 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/24 12:23:08 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_u32	app_get_width(t_app *cube)
{
	return (cube->image->width);
}

t_u32	app_get_height(t_app *cube)
{
	return (cube->image->height);
}

t_f64	app_get_delta_time(t_app *cube)
{
	return (cube->mlx->delta_time);
}
