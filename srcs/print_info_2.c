/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/25 11:53:06 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_time_2(char *to_split)
{
	char		**split_2;

	split_2 = ft_strsplit(to_split, ':');
	if (split_2 && split_2[0] && split_2[1])
	{
		ft_putstr(split_2[0]);
		ft_putstr(":");
		ft_putstr(split_2[1]);
		ft_putchar(' ');
		free_table(split_2);
	}
}

void		print_time(struct stat sb)
{
	char		*time;
	char		**split;

	time = ctime(&sb.st_ctime);
	if (time)
	{
		split = ft_strsplit(time, ' ');
		if (split && split[1] && split[2] && split[3])
		{
			ft_putstr(split[1]);
			ft_putchar(' ');
			ft_putstr(split[2]);
			if (ft_strlen(split[2]) == 1)
				ft_putchar(' ');
			ft_putchar(' ');
			print_time_2(split[3]);
			free_table(split);
		}
	}
}

void		print_color(char *path, t_data *data)
{
	char 		*new_path;

	new_path = get_new_path(path, data);
	if (data->gg && is_exec(new_path) && !is_dir(new_path))
	{	
		ft_putstr("\033[0;31m");
		ft_putstr(path);
	 	ft_putstr("\033[0m");
	}
	else if (data->gg && is_dir(new_path))
	{	
		ft_putstr("\033[1;36m");
		ft_putstr(path);
	 	ft_putstr("\033[0m");
	}
	else if (data->gg && is_sym(new_path))
	{	
		ft_putstr("\033[0;35m");
		ft_putstr(path);
	 	ft_putstr("\033[0m");
	}
	else
		ft_putstr(path);
	free(new_path);
}
