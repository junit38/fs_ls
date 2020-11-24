/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:24:16 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_new_path(char *table, t_data *data)
{
	char		*new_path;

	new_path = NULL;
	if (data->path)
	{
		new_path = ft_strdup(data->path);
		new_path = ft_strcat(new_path, "/");
		new_path = ft_strcat(new_path, table);
	}
	else
		new_path = ft_strdup(table);
	return (new_path);
}
