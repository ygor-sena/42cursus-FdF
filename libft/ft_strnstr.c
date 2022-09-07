/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:44:30 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/27 15:17:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	size_len;

	i = 0;
	size_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *) big);
	while ((big[i] != '\0') && (i < len))
	{
		if ((ft_strncmp(&big[i], little, size_len) == 0)
			&& (i + size_len <= len))
		{
			return ((char *) &big[i]);
		}
		i++;
	}
	return (0);
}
