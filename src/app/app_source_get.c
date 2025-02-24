/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_source_get.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:33:57 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	*app_source_get(t_app *cube, const char *key)
{
	return (storage_get(&cube->storage, key));
}
