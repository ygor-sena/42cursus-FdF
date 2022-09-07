/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:47:28 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/24 18:04:57 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n);
static int	count_digits_to_str(int n);

char	*ft_itoa(int n)
{
	int		len_n;
	int		neg;
	char	*str_n;

	if (n == -2147483648)
	{
		str_n = ft_strdup("-2147483648");
		return (str_n);
	}
	neg = is_negative(n);
	len_n = count_digits_to_str(n);
	str_n = ft_calloc(len_n + 1, sizeof(*str_n));
	if (neg == 1)
		n *= -1;
	while (len_n > 0)
	{
		str_n[len_n - 1] = n % 10 + '0';
		n /= 10;
		len_n--;
	}	
	if (neg == 1)
		str_n[len_n] = '-';
	return (str_n);
}

static int	count_digits_to_str(int n)
{
	int	digits;

	digits = 1;
	if (is_negative(n) == 1)
	{
		n *= -1;
		digits++;
	}
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}
