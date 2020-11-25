/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/25 11:26:37 by mery             ###   ########.fr       */
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

void		ft_ls_sym(char *path, t_data *data)
{
	char	**table;

	free(data->path);
	data->path = NULL;
	table = init_table(1);
	if (table)
	{
		table[0] = ft_strdup(path);
		get_data_info(table, data);
		print_info(path, data);
		free_table(table);
	}
}

void		print_total(t_data *data)
{
	if (data->l)
	{
		ft_putstr("total ");
		ft_putnbr(data->total);
		ft_putchar('\n');
	}
}
