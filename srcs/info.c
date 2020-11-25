/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/25 11:21:42 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_block_size(char *path)
{
	struct stat sb;

	if (stat(path, &sb) != -1)
		return (sb.st_blocks);
	return (0);
}

void		get_data_info_file(char **table, t_data *data)
{
	int				i;

	i = 0;
	while (table[i])
	{
		if (is_file(table[i]) && !is_dir(table[i]))
		{
			if (get_size_len(table[i]) > data->size_len)
				data->size_len = get_size_len(table[i]);
			if (get_nlink_len(table[i]) > data->nlink_len)
				data->nlink_len = get_nlink_len(table[i]);
			if (get_owner_len(table[i]) > data->owner_len)
				data->owner_len = get_owner_len(table[i]);
			if (get_group_len(table[i]) > data->group_len)
				data->group_len = get_group_len(table[i]);
		}
		i++;
	}
}

void		get_data_info(char **table, t_data *data)
{
	int				i;
	char			*new_path;

	i = 0;
	data->total = 0;
	while (table[i])
	{
		new_path = get_new_path(table[i], data);
		if (get_size_len(new_path) > data->size_len)
			data->size_len = get_size_len(new_path);
		if (get_nlink_len(new_path) > data->nlink_len)
			data->nlink_len = get_nlink_len(new_path);
		if (get_owner_len(new_path) > data->owner_len)
			data->owner_len = get_owner_len(new_path);
		if (get_group_len(new_path) > data->group_len)
			data->group_len = get_group_len(new_path);
		data->total += get_block_size(new_path);
		free(new_path);
		i++;
	}
}
