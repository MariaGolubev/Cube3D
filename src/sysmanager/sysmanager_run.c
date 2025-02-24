/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sysmanager_run.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 22:11:19 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 11:17:11 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sysmanager.h"

t_u64	sysmanager_run(t_sysmanager *sysmanager, void *data)
{
	int		i;
	t_u64	event;

	i = 0;
	while (i < sysmanager->count && sysmanager->systems[i].system != NULL
		&& sysmanager->event_mask != EVENT_EXIT_MSK)
	{
		if ((sysmanager->event_mask) & sysmanager->systems[i].event_mask)
			sysmanager->event_mask |= sysmanager->systems[i].system(data);
		i++;
	}
	event = sysmanager->event_mask;
	sysmanager->event_mask = EVENT_ALWAYS_MSK;
	return (event);
}
