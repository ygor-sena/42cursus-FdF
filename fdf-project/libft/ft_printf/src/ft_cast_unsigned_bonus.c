/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:31:45 by yde-goes          #+#    #+#             */
/*   Updated: 2022/07/22 15:43:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_cast_unsigned(t_format *input)
{
	unsigned int	nbr;
	char			*str_nbr;

	nbr = va_arg(input->arg, unsigned int);
	str_nbr = ft_utoa_base(nbr, DECIMAL_BASE);
	input->size += write(1, str_nbr, ft_strlen(str_nbr));
	free(str_nbr);
}
