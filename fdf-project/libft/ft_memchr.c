/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:59:28 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/27 16:15:28 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*cast_s;

	cast_s = (t_byte *) s;
	if (!cast_s || n == 0)
		return (NULL);
	while (n--)
	{
		if (*cast_s == (t_byte) c)
			return ((void *) cast_s);
		cast_s++;
	}	
	return (NULL);
}
