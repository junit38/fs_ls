/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:27:06 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_dir_len(char *path, t_data *data)
{
	DIR				*dir;
	struct dirent	*dirent;
	int				len;

	len = 0;
	dir = opendir(path);
	if (dir)
	{
		while ((dirent = readdir(dir)) != NULL)
		{
			if ((dirent->d_name[0] == '.' && data->a)
				|| (dirent->d_name[0] != '.'))
				len++;
		}
		closedir(dir);
	}
	return (len);
}
