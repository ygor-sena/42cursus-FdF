/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:19:54 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/24 18:09:23 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*cast_s;
	size_t	len;

	if ((char *)s == NULL)
		return (NULL);
	len = (ft_strlen(s) + 1);
	dest = malloc(len * sizeof(*dest));
	cast_s = (char *) s;
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, cast_s, len);
	return (dest);
}
