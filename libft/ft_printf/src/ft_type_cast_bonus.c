/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:43:50 by yde-goes          #+#    #+#             */
/*   Updated: 2022/07/22 04:48:38 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_type_cast(t_format *input, t_flag flag)
{
	if (input->format[input->index] == 'c')
		ft_cast_char(input);
	else if (input->format[input->index] == '%')
		ft_cast_percent(input);
	else if (input->format[input->index] == 's')
		ft_cast_string(input);
	else if (input->format[input->index] == 'p')
		ft_cast_pointer(input);
	else if (input->format[input->index] == 'u')
		ft_cast_unsigned(input);
	else if (input->format[input->index] == 'd'
		|| input->format[input->index] == 'i')
		ft_cast_integer(input, flag);
	else if (input->format[input->index] == 'x'
		|| input->format[input->index] == 'X')
		ft_cast_hexa(input, flag);
}
