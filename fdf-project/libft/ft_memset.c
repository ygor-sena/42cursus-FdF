/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:01:18 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/27 16:21:07 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	t_byte	*cast_s;

	i = 0;
	cast_s = s;
	while (i < n)
	{
		cast_s[i] = c;
		i++;
	}
	return (cast_s);
}
