/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 16:36:08 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_files_len(char **table)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (table[i])
	{
		if (is_file(table[i]) && !is_dir(table[i]))
			len++;
		i++;
	}
	return (len);
}

int			get_dirs_len(char **table)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (table[i])
	{
		if (is_dir(table[i]))
			len++;
		i++;
	}
	return (len);
}

void		ft_ls_exist(char **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		if (!is_file(table[i]) && !is_dir(table[i]))
		{
			ft_putstr("./ft_ls: ");
			ft_putstr(table[i]);
			ft_putendl(": No such file or directory");
		}
		i++;
	}
}

void		ft_ls_files(char **table, t_data *data)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = get_files_len(table);
	get_data_info_file(table, data);
	while (table[i])
	{
		if (is_file(table[i]) && !is_dir(table[i]))
		{
			if (data->l == 1)
				print_info(table[i], data);
			else
				ft_putstr(table[i]);
			j++;
			if (j < len && !data->l)
				ft_putchar(' ');
		}
		i++;
	}
	if (len > 0 && !data->l)
		ft_putchar('\n');
}

void		ft_ls_dirs(char **table, t_data *data, int is_alone)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = get_dirs_len(table);
	while (table[i])
	{
		if (is_dir(table[i]))
		{
			ft_ls_dir(table[i], data, is_alone);
			j++;
			if (j < len)
				ft_putchar('\n');
		}
		i++;
	}
}
