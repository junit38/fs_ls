/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 14:57:57 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

typedef struct		s_data
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	char			*path;
	int				size_len;
	int				nlink_len;
	int				owner_len;
	int				group_len;
}					t_data;

#endif