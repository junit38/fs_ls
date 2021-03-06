/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:30:30 by jmery             #+#    #+#             */
/*   Updated: 2013/11/26 13:34:01 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_putendl_fd(char const *s, int fd)
{
	char	*p;

	p = (char*)s;
	while (*p != '\0')
	{
		ft_putchar_fd(*p, fd);
		p++;
	}
	ft_putchar_fd('\n', fd);
}
