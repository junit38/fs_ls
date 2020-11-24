/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 16:49:32 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_table_len(char **table)
{
	int		i;

	i = 0;
	if (table)
	{
		while (table[i])
			i++;
	}
	return (i);
}

void		print_table(char **table, t_data *data)
{
	int		i;

	i = 0;
	if (table)
	{
		while (table[i])
		{
			if (data->l)
				print_info(table[i], data);
			else
			{
				ft_putstr(table[i]);
				if (table[i + 1])
					ft_putchar(' ');
			}
			i++;
		}
		if (!data->l)
			ft_putchar('\n');
	}
}

void		reverse_table(char **table)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (i < get_table_len(table) / 2)
	{
		j = get_table_len(table) - i - 1;
		swap = table[i];
		table[i] = table[j];
		table[j] = swap;
		j++;
		i++;
	}
}

void		free_table(char **table)
{
	int		i;

	if (table)
	{
		i = 0;
		while (table[i])
		{
			free(table[i]);
			i++;
		}
		if (table)
			free(table);
	}
}

char		**init_table(int len)
{
	char		**new_table;

	new_table = (char**)malloc(sizeof(*new_table) * (len + 1));
	if (new_table)
		new_table[len] = NULL;
	return (new_table);
}
