/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:17:14 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data		*init_data(void)
{
	t_data	*data;

	data = NULL;
	data = (t_data*)malloc(sizeof(*data));
	if (data)
	{
		data->l = 0;
		data->R = 0;
		data->a = 0;
		data->r = 0;
		data->t = 0;
		data->path = NULL;
		data->size_len = 0;
		data->nlink_len = 0;
		data->owner_len = 0;
		data->group_len = 0;
	}
	return (data);
}
