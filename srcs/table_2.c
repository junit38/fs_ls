/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:24:35 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_table(char **table)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (table && table[i])
	{
		j = i;
		while (table[j])
		{
			if (ft_strcmp(table[i], table[j]) > 0)
			{
				swap = table[i];
				table[i] = table[j];
				table[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void		sort_table_reverse(char **table)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (table && table[i])
	{
		j = i;
		while (table[j])
		{
			if (ft_strcmp(table[i], table[j]) < 0)
			{
				swap = table[i];
				table[i] = table[j];
				table[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int			check_swap(char *table_1, char *table_2, t_data *data)
{
	char		*new_path_1;
	char		*new_path_2;

	new_path_1 = get_new_path(table_1, data);
	new_path_2 = get_new_path(table_2, data);
	if (get_time(new_path_1) < get_time(new_path_2))
		return (1);
	return (0);
}

void		sort_table_time(char **table, t_data *data)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (table[i])
	{
		j = i;
		while (table[j])
		{
			if (check_swap(table[i], table[j], data))
			{
				swap = table[i];
				table[i] = table[j];
				table[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void		swap_folders(char **table)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (table[i])
	{
		j = i;
		while (table[j])
		{
			if (ft_strcmp(table[i], "..") == 0 &&
				ft_strcmp(table[j], ".") == 0) 
			{
				swap = table[i];
				table[i] = table[j];
				table[j] = swap;
			}
			j++;
		}
		i++;
	}
}
