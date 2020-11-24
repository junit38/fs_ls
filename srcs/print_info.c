/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:03:01 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_permission(struct stat sb)
{
	ft_putstr(S_ISDIR(sb.st_mode) ? "d" : "-");
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

void        print_owner(struct stat sb, t_data *data)
{
    struct passwd   *pwd;
    struct group    *gr;

    pwd = getpwuid(sb.st_uid);
    ft_putstr(pwd->pw_name);
    ft_putnchar(' ', data->owner_len - ft_strlen(pwd->pw_name) + 1);
    gr = getgrgid(sb.st_gid);
    ft_putstr(gr->gr_name);
    ft_putnchar(' ', data->group_len - ft_strlen(gr->gr_name) + 1);
}

void        print_time(struct stat sb)
{
    char        *time;
    char        **split;
    char        **split_2;

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
            split_2 = ft_strsplit(split[3], ':');
            if (split_2 && split_2[0] && split_2[1])
            {
                ft_putstr(split_2[0]);
                ft_putstr(":");
                ft_putstr(split_2[1]);
                ft_putchar(' ');
                free_table(split_2);
            }
            free_table(split);
        }
    }
}

void        print_info_file(char *p, char *n_p, struct stat sb, t_data *data)
{
    ssize_t     buflen;

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
    ft_putchar('\n');
}

void		print_info(char *path, t_data *data)
{
	struct stat sb;
    char        *new_path;

    new_path = NULL;
    if (data->path)
    {
        new_path = ft_strdup(data->path);
        new_path = ft_strcat(new_path, "/");
        new_path = ft_strcat(new_path, path);
    }
    else
        new_path = ft_strdup(path);
    if (stat(new_path, &sb) != -1)    
        print_info_file(path, new_path, sb, data);
    free(new_path);
}
