/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_pointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:31:39 by yde-goes          #+#    #+#             */
/*   Updated: 2022/07/22 15:43:22 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_cast_pointer(t_format *input)
{
	unsigned long	nbr;
	char			*str_nbr;

	nbr = va_arg(input->arg, unsigned long);
	if (!nbr)
	{
		str_nbr = ft_strdup(NULL_PTR);
		input->size += write(1, str_nbr, ft_strlen(str_nbr));
	}
	else
	{
		str_nbr = ft_utoa_base(nbr, LOW_HEX_BASE);
		input->size += write(1, LOW_HEX_PREFIX, ft_strlen(LOW_HEX_PREFIX));
		input->size += write(1, str_nbr, ft_strlen(str_nbr));
	}
	free(str_nbr);
}
