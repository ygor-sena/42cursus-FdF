/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:11:33 by yde-goes          #+#    #+#             */
/*   Updated: 2022/08/29 20:24:24 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	check_base(char *base);
static int	convert_string(char *str, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	signal;

	signal = 1;
	if (!check_base(base))
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	if (*str == '0')
	{
		str++;
		if (*str == 'x')
			str++;
	}
	return (signal * convert_string(str, base));
}

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base)
		return (1);
	if (ft_strlen(base) <= 1)
		return (1);
	while (base[i])
	{
		j = 0;
		while (base[i + j])
		{
			if (base[i + j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	convert_string(char *str, char *base)
{
	int	nbr_sys;
	int	nbr_conv;
	int	i;
	int	ch;

	i = 0;
	nbr_sys = ft_strlen(base);
	nbr_conv = 0;
	while (ft_strchr(base, ft_tolower(str[i])) && str[i])
	{
		ch = 0;
		while (base[ch] != ft_tolower(str[i]) && base[ch])
			ch++;
		nbr_conv = (nbr_conv * nbr_sys) + ch;
		i++;
	}
	return (nbr_conv);
}
