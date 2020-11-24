/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/23 14:02:41 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		else if (ft_strcmp(argv[i], "-l") == 0)
			data->l = 1;
		else if (ft_strcmp(argv[i], "-R") == 0)
			data->R = 1;
		else if (ft_strcmp(argv[i], "-a") == 0)
			data->a = 1;
		else if (ft_strcmp(argv[i], "-r") == 0)
			data->r = 1;
		else if (ft_strcmp(argv[i], "-t") == 0)
			data->t = 1;
		i++;
	}
	if (stop)
		return (i - 1);
	return (i);
}

void		print_options(t_data *data)
{
	if (data->l)
		ft_putstr("-l ");
	if (data->R)
		ft_putstr("-R ");
	if (data->a)
		ft_putstr("-a ");
	if (data->r)
		ft_putstr("-r ");
	if (data->t)
		ft_putstr("-t ");
}