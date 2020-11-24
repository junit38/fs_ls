/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:37:40 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:42:43 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*p;
	unsigned int	i;

	p = b;
	i = 0;
	while (i < len)
	{
		*p = (char)c;
		p++;
		i++;
	}
	return (b);
}