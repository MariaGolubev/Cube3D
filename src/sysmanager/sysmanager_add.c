/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sysmanager_add.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 20:42:48 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/24 20:26:00 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sysmanager.h"

int	sysmanager_add(t_sysmanager *sysmanager, t_sys_fn system, t_u64 event_mask)
{
	if (sysmanager->count >= MAX_SYSTEMS)
		return (1);
	sysmanager->systems[sysmanager->count].system = system;
	sysmanager->systems[sysmanager->count].event_mask = event_mask;
	sysmanager->count++;
	return (0);
}
