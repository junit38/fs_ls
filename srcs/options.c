/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/25 12:32:30 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_options_2(t_data *data, char *argv)
{
	if (ft_strchr(argv, 'l'))
		data->l = 1;
	if (ft_strchr(argv, 'R'))
		data->rr = 1;
	if (ft_strchr(argv, 'a'))
		data->a = 1;
	if (ft_strchr(argv, 'r'))
		data->r = 1;
	if (ft_strchr(argv, 't'))
		data->t = 1;
	if (ft_strchr(argv, 'G'))
		data->gg = 1;
	if (ft_strchr(argv, '1'))
		data->one = 1;
}

int		init_options(t_data *data, int argc, char **argv)
{
	int		i;
	int		stop;

	i = 1;
	stop = 0;
	while (i < argc && stop == 0)
	{
		if (argv[i][0] != '-')
			stop = 1;
		else
			init_options_2(data, argv[i]);
		i++;
	}
	if (stop)
		return (i - 1);
	return (i);
}
