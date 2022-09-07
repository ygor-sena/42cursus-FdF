/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 23:08:19 by yde-goes          #+#    #+#             */
/*   Updated: 2022/07/22 04:48:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	ft_vfprintf(va_list arg, const char *format);

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	arg;

	length = 0;
	if (!format)
		return (0);
	va_start(arg, format);
	length = ft_vfprintf(arg, format);
	va_end(arg);
	return (length);
}

static int	ft_vfprintf(va_list arg, const char *format)
{
	t_format	input;
	t_flag		flag;
	size_t		length;

	input = ft_instance_format(arg, format);
	flag = ft_instance_flag();
	length = 0;
	while (input.format[input.index])
	{
		if (input.format[input.index] == '%')
			ft_sort_format(&input, flag);
		else
			input.size += write(1, &input.format[input.index], 1);
		input.index++;
	}
	length = input.size;
	return (length);
}
