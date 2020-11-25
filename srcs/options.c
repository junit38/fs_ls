/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/25 11:57:48 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_options_2(t_data *data, char *argv)
{
	if (ft_strcmp(argv, "-l") == 0)
		data->l = 1;
	else if (ft_strcmp(argv, "-R") == 0)
		data->rr = 1;
	else if (ft_strcmp(argv, "-a") == 0)
		data->a = 1;
	else if (ft_strcmp(argv, "-r") == 0)
		data->r = 1;
	else if (ft_strcmp(argv, "-t") == 0)
		data->t = 1;
	else if (ft_strcmp(argv, "-G") == 0)
		data->gg = 1;
	else if (ft_strcmp(argv, "-1") == 0)
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
