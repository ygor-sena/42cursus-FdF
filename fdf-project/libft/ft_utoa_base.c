/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:46:27 by yde-goes          #+#    #+#             */
/*   Updated: 2022/07/16 16:16:49 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_base_digit(unsigned long nbr, size_t base);

char	*ft_utoa_base(unsigned long nbr, char *base)
{
	size_t	nbr_sys;
	size_t	digits;
	char	*to_str;

	if (!base)
		return (NULL);
	nbr_sys = ft_strlen(base);
	digits = count_base_digit(nbr, nbr_sys);
	to_str = ft_calloc(digits + 1, sizeof(*to_str));
	while (digits > 0)
	{
		to_str[digits - 1] = base[nbr % nbr_sys];
		nbr /= nbr_sys;
		digits--;
	}
	return (to_str);
}

static size_t	count_base_digit(unsigned long nbr, size_t base)
{
	size_t	digits;

	digits = 1;
	while (nbr >= base)
	{
		nbr /= base;
		digits++;
	}	
	return (digits);
}
