/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:40:28 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/23 00:06:15 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest >= src)
	{
		while (n--)
			((t_byte *)dest)[n] = ((t_byte *)src)[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
