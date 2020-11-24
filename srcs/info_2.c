/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:28:15 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_nb_len(int size)
{
	int			len;
	int			nb;

	len = 0;
	nb = size;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int			get_size_len(char *path)
{
	struct stat sb;

	if (stat(path, &sb) != -1)
		return (get_nb_len(sb.st_size));
	return (0);
}

int			get_nlink_len(char *path)
{
	struct stat sb;

	if (stat(path, &sb) != -1)
		return (get_nb_len(sb.st_nlink));
	return (0);
}

int			get_owner_len(char *path)
{
	struct stat		sb;
	struct passwd	*pwd;

	if (stat(path, &sb) != -1)
	{
		pwd = getpwuid(sb.st_uid);
		return (ft_strlen(pwd->pw_name));
	}
	return (0);
}

int			get_group_len(char *path)
{
	struct stat		sb;
	struct group	*gr;

	if (stat(path, &sb) != -1)
	{
		gr = getgrgid(sb.st_gid);
		return (ft_strlen(gr->gr_name));
	}
	return (0);
}
