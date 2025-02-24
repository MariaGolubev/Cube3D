/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sysmanager_add_event.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 22:57:33 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/21 20:42:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sysmanager.h"

void	sysmanager_add_event(t_sysmanager *sysmanager, t_u64 event)
{
	sysmanager->event_mask |= event;
}
