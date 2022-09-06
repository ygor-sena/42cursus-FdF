/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:53:59 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 20:38:37 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	instance_map(t_map *map)
{
	map->projection = ISOMETRIC;
	map->is_colored = FALSE;
	map->usr_z_axis = 1;
	map->transl_x = 0;
	map->transl_y = 0;
	map->roll_x = 0;
	map->pitch_y = 0;
	map->yaw_z = 0;
}

t_file	**instance_coord(int width, int length)
{
	t_file	**coord;
	int		x;

	coord = malloc(width * sizeof(t_file *));
	if (!coord)
		return (NULL);
	x = 0;
	while (x < width)
	{
		coord[x] = malloc(length * sizeof(t_file));
		if (!coord[x])
			return (NULL);
		x++;
	}
	return (coord);
}

t_bresenham	instance_values(t_point *p1, t_point *p2)
{
	t_bresenham	b;

	b.x0 = 0;
	b.y0 = 0;
	b.dx = p2->x - p1->x;
	b.dy = p2->y - p1->y;
	b.dx1 = ft_abs(b.dx);
	b.dy1 = ft_abs(b.dy);
	b.px = 2 * b.dy1 - b.dx1;
	b.py = 2 * b.dx1 - b.dy1;
	b.xe = 0;
	b.ye = 0;
	return (b);
}
