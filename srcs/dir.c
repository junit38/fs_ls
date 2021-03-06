/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/25 11:40:15 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(char *path)
{
	struct stat sb;

	if (stat(path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode))
			return (1);
	}
	return (0);
}

int		is_sym(char *path)
{
	struct stat sb;

	if (lstat(path, &sb) != -1)
	{
		if (S_ISLNK(sb.st_mode))
			return (1);
	}
	return (0);
}

int		is_file(char *path)
{
	struct stat sb;

	if (stat(path, &sb) != -1)
		return (1);
	return (0);
}

int		is_exec(char *path)
{
	struct stat sb;

	if (stat(path, &sb) != -1)
	{
		if (S_IEXEC & sb.st_mode)
			return (1);
	}
	return (0);
}

int		get_time(char *path)
{
	struct stat sb;

	if (stat(path, &sb) != -1)
		return (sb.st_ctime);
	return (0);
}
