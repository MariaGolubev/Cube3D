/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sysmanager_init.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 20:42:57 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/24 20:25:56 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sysmanager.h"

int	sysmanager_init(t_sysmanager *sysmanager)
{
	int	i;

	i = 0;
	while (i < MAX_SYSTEMS)
	{
		sysmanager->systems[i].system = NULL;
		sysmanager->systems[i].event_mask = 0;
		i++;
	}
	sysmanager->event_mask = EVENT_ALWAYS_MSK;
	sysmanager->count = 0;
	return (0);
}
