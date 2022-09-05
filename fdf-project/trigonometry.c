/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:11:15 by yde-goes          #+#    #+#             */
/*   Updated: 2022/08/31 19:32:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int	main(void)
{
	float a;
	float b;

	a = cos(30);
	b = sin(30);
	printf("Cos is %.6f\n", a);
	printf("Sen is %.6f\n", b);
	return (0);
}

/* int get_scale2(t_map *map)
{
	int x;
	int y;
	int new;

	x = MLX_WIDTH / map->width_x;
	y = MLX_HEIGHT / map->length_y;
	new = ft_min(map->width_x, map->length_y);
	if (new < 4)
		return (2);
	return (new);
} */
