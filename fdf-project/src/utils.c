/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:29:14 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/03 02:22:57 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	free_coord(t_file **coord, int width_x)
{
	int	i;

	i = 0;
	while (i < width_x)
	{
		free(coord[i]);
		i++;
	}
	free(coord);
}

void	free_split(char **split)
{
	int	x;

	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
}
