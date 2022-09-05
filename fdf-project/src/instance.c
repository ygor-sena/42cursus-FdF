/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:53:59 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/05 04:46:07 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	instance_map(t_map *map)
{
	//map->coord = NULL;
	//map->scale.x = 0;
	//map->scale.y = 0;
	//map->scale_factor = 0;
	//map->width_x = 0;
	//map->length_y = 0;
	map->is_colored = FALSE;
	map->projection = ISOMETRIC;
	//User stardard values
	map->usr_z_axis = 1;
	map->transl_x = 0;
	map->transl_y = 0;
	/* map->roll_x = 0;
	map->pitch_y = 0;
	map->yaw_z = 0; */
	/* map->rotation.Axx =  0;
	map->rotation.Axy = 0;
	map->rotation.Axz = 0; */
}

t_file	**instance_coord(int width, int length)
{
	/* t_point	**coord;
	int		x;
	int		y;

	coord = malloc(width * sizeof(t_point *));
	if (!coord)
		return (NULL);
	x = 0;
	while (x < width)
	{
		coord[x] = malloc(length * sizeof(t_point));
		if (!coord[x])
			return (NULL);
		y = 0;
		while (y < length)
		{
			coord[x][y].x = 0;
			coord[x][y].y = 0;
			coord[x][y].z = 0;
			coord[x][y].color = 0;
			y++;
		}
		x++;
	} */
	t_file	**coord;
	int		x;

	coord = calloc(width, sizeof(t_file *));
	if (!coord)
		return (NULL);
	x = 0;
	while (x < width)
	{
		coord[x] = calloc(length, sizeof(t_file));
		if (!coord[x])
			return (NULL);
		x++;
	}
	return (coord);
}

t_bresenham	instance_values(t_stroke line)
{
	t_bresenham	b;
	//LATER CREATE MY OWN FT_ABS
	b.x0 = 0;
	b.y0 = 0;
	b.dx = line.end.x - line.start.x;
	b.dy = line.end.y - line.start.y;
	b.dx1 = ft_abs(b.dx);
	b.dy1 = ft_abs(b.dy);
	b.px = 2 * b.dy1 - b.dx1;
	b.py = 2 * b.dx1 - b.dy1;
	b.xe = 0;
	b.ye = 0;
	b.ref = 0;
	return (b);
}

t_point	set_point(void)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	point.z = 0;
	point.color = 0;
	return (point);
}
