/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:32:14 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_recursive(char **table, t_data *data, char *path)
{
	int		i;
	char	*new_path;

	i = 0;
	while (table[i])
	{
		new_path = NULL;
		new_path = ft_strdup(path);
		new_path = strcat(new_path, "/");
		new_path = strcat(new_path, table[i]);
		if (new_path && is_dir(new_path) && ft_strcmp(table[i], ".") != 0
			&& ft_strcmp(table[i], "..") != 0)
		{
			ft_putchar('\n');
			ft_ls_dir(new_path, data, 0);
		}
		free(new_path);
		i++;
	}
}

void		ft_ls_dir_2(DIR *dir, char **table, t_data *data, char *path)
{
	struct dirent	*dirent;
	int				i;

	i = 0;
	while ((dirent = readdir(dir)) != NULL)
	{
		if ((dirent->d_name[0] == '.' && data->a)
			|| (dirent->d_name[0] != '.'))
		{
			table[i] = ft_strdup(dirent->d_name);
			i++;
		}
	}
	get_data_info(table, data);
	sort_table(table);
	if (data->t)
		sort_table_time(table, data);
	if (data->r)
	{
		reverse_table(table);
		swap_folders(table);
	}
	print_table(table, data);
	if (data->rr == 1)
		ft_ls_recursive(table, data, path);
}

void		ft_ls_dir(char *path, t_data *data, int is_alone)
{
	DIR				*dir;
	char			**table;

	if (data->path)
		free(data->path);
	data->path = ft_strdup(path);
	dir = opendir(path);
	if (dir)
	{
		if (!is_alone)
		{
			ft_putstr(path);
			ft_putendl(":");
		}
		table = init_table(get_dir_len(path, data));
		if (table)
			ft_ls_dir_2(dir, table, data, path);
		free_table(table);
		closedir(dir);
	}
}

void		main_multi(int argc, char **argv, t_data *data, int i)
{
	int		is_alone;
	int		j;
	char	**table;

	is_alone = 0;
	if (i + 1 == argc)
		is_alone = 1;
	table = init_table(argc - i);
	j = 0;
	while (i < argc)
	{
		table[j] = ft_strdup(argv[i]);
		j++;
		i++;
	}
	sort_table(table);
	if (!data->r)
		reverse_table(table);
	ft_ls_exist(table);
	ft_ls_files(table, data);
	if (get_files_len(table) > 0 && get_dirs_len(table) > 0)
		ft_putchar('\n');
	ft_ls_dirs(table, data, is_alone);
	free_table(table);
}

int			main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	data = init_data();
	if (argc > 1)
	{
		i = init_options(data, argc, argv);
		if (i == argc)
			ft_ls_dir(".", data, 1);
		main_multi(argc, argv, data, i);
	}
	else
		ft_ls_dir(".", data, 1);
	free(data->path);
	free(data);
	return (0);
}
