/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/12 13:02:43 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 14:24:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_path(const char *path, const char *ext)
{
	size_t	path_len;
	size_t	ext_len;

	path_len = ft_strlen(path);
	ext_len = ft_strlen(ext);
	if (path_len < ext_len || ft_strncmp(path + path_len - ext_len, ext,
			ext_len) != 0)
		return (1);
	return (0);
}

void	exiterr(t_app *app, const char *msg, bool sys, int status)
{
	if (sys)
		perror(msg);
	else
		ft_putendl_fd(msg, 2);
	app_destroy(app);
	exit(status);
}
