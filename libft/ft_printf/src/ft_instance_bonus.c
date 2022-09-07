/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:19:52 by yde-goes          #+#    #+#             */
/*   Updated: 2022/07/22 04:48:27 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

t_format	ft_instance_format(va_list arg, const char *format)
{
	t_format	input;

	va_copy(input.arg, arg);
	input.format = format;
	input.size = 0;
	input.index = 0;
	return (input);
}

t_flag	ft_instance_flag(void)
{
	t_flag	flag;

	flag.padding = FALSE;
	flag.field = 0;
	flag.precision = FALSE;
	flag.length = 0;
	flag.left_just = FALSE;
	flag.hashtag = FALSE;
	flag.sign = FALSE;
	flag.space = FALSE;
	flag.spec = ' ';
	flag.error = FALSE;
	return (flag);
}

void	ft_reset_flag(t_flag *flag)
{
	flag->padding = FALSE;
	flag->field = 0;
	flag->precision = FALSE;
	flag->length = 0;
	flag->left_just = FALSE;
	flag->hashtag = FALSE;
	flag->sign = FALSE;
	flag->padding = FALSE;
	flag->spec = ' ';
	flag->error = FALSE;
}
