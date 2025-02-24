/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_event_add.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 10:32:22 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_event_add(t_app *cube, t_u64 event_mask)
{
	sysmanager_add_event(&cube->sysmanager, event_mask);
}
