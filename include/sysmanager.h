/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sysmanager.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 22:03:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 11:20:00 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSMANAGER_H
# define SYSMANAGER_H
# include "storage.h"
# include "types.h"
# include <stdlib.h>

# define MAX_SYSTEMS 128
# define EVENT_ALWAYS_MSK 9223372036854775808ULL
# define EVENT_EXIT_MSK 4611686018427387904ULL
# define EVENT_RESIZE_MSK 2305843009213693952ULL
# define EVENT_NONE_MSK 0

typedef t_u64	(*t_sys_fn)(void *data);

typedef struct s_system
{
	t_u64		event_mask;
	t_sys_fn	system;
}				t_system;

typedef struct s_sysmanager
{
	t_u64		event_mask;
	t_system	systems[MAX_SYSTEMS];
	int			count;
}				t_sysmanager;

int				sysmanager_init(t_sysmanager *sysmanager);
void			sysmanager_add_event(t_sysmanager *sysmanager, t_u64 event);
t_u64			sysmanager_run(t_sysmanager *sysmanager, void *data);
int				sysmanager_add(t_sysmanager *sysmanager, t_sys_fn system,
					t_u64 event_mask);

#endif
