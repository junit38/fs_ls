/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/25 11:31:34 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_permission(struct stat sb)
{
	if (S_ISDIR(sb.st_mode))
		ft_putstr("d");
	else if (S_ISLNK(sb.st_mode))
		ft_putstr("l");
	else
		ft_putstr("-");
	ft_putstr(sb.st_mode & S_IRUSR ? "r" : "-");
	ft_putstr(sb.st_mode & S_IWUSR ? "w" : "-");
	ft_putstr(sb.st_mode & S_IXUSR ? "x" : "-");
	ft_putstr(sb.st_mode & S_IRGRP ? "r" : "-");
	ft_putstr(sb.st_mode & S_IWGRP ? "w" : "-");
	ft_putstr(sb.st_mode & S_IXGRP ? "x" : "-");
	ft_putstr(sb.st_mode & S_IROTH ? "r" : "-");
	ft_putstr(sb.st_mode & S_IWOTH ? "w" : "-");
	ft_putstr(sb.st_mode & S_IXOTH ? "x" : "-");
}

void		print_owner(struct stat sb, t_data *data)
{
	struct passwd	*pwd;
	struct group	*gr;

	pwd = getpwuid(sb.st_uid);
	ft_putstr(pwd->pw_name);
	ft_putnchar(' ', data->owner_len - ft_strlen(pwd->pw_name) + 1);
	gr = getgrgid(sb.st_gid);
	ft_putstr(gr->gr_name);
	ft_putnchar(' ', data->group_len - ft_strlen(gr->gr_name) + 1);
}

void		print_symlink(char *new_path)
{
	char 	buf[1024];
	ssize_t len;

	if ((len = readlink(new_path, buf, sizeof(buf)-1)) != -1)
	{
	    buf[len] = '\0';
	    ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

void		print_info_file(char *p, char *n_p, struct stat sb, t_data *data)
{
	ssize_t		buflen;

	print_permission(sb);
	buflen = listxattr(n_p, NULL, 0, 0);
	if (buflen)
		ft_putchar('@');
	else
		ft_putchar(' ');
	ft_putnchar(' ', data->nlink_len - get_nb_len(sb.st_nlink) + 1);
	ft_putnbr(sb.st_nlink);
	ft_putchar(' ');
	print_owner(sb, data);
	ft_putnchar(' ', data->size_len - get_nb_len(sb.st_size) + 1);
	ft_putnbr(sb.st_size);
	ft_putchar(' ');
	print_time(sb);
	ft_putstr(p);
	if (is_sym(n_p))
		print_symlink(n_p);
	ft_putchar('\n');
}

void		print_info(char *path, t_data *data)
{
	struct stat sb;
	char		*new_path;

	new_path = get_new_path(path, data);
	if (lstat(new_path, &sb) != -1)
		print_info_file(path, new_path, sb, data);
	free(new_path);
}
