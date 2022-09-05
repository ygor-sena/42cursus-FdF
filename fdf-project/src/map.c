/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:50:29 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/05 15:10:40 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* void	set_map(char *file_name, t_map *map)
{
	map->width_x = get_width(file_name);
	if (map->width_x == -1)
		return (0);
	map->length_y = get_length(file_name);
	map->coord = instance_coord(map->width_x, map->length_y);
	if (!map->coord)
		return (0);
	fill_axes(file_name, map); //THIRD PARAMETER FOR PROJECTION ?
} */

int	get_scale(t_map *map)
{
	int	area;
	int	scale;

	area = (MLX_HEIGHT * MLX_WIDTH) / 4;
	scale = sqrt(area / (map->length_y * map->width_x));
	if (scale < 2)
		return (2);
	return (scale);
}

void	set_isometric(t_point *point)
{
	int	tmp;

	tmp = point->x;
	point->x = (tmp - point->y) * SINE_30;
	point->y = (tmp + point->y) \
			* COSINE_30 - point->z;
}


/* void	set_isometric(t_map *map, int x, int y)
{
	int	tmp;

	tmp = map->coord[x][y].x;
	map->coord[x][y].x = (tmp - map->coord[x][y].y) * SINE_30 ;
	map->coord[x][y].y = (tmp + map->coord[x][y].y) \
			* COSINE_30 - map->coord[x][y].z;
} */

/* void	set_to_center(t_map *map, int x, int y)
{
	map->coord[x][y].x += MLX_WIDTH / 2;
	map->coord[x][y].y += MLX_HEIGHT / 2;
} */

/* void	fit_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	//standard_values(t_map *map);
	//map->scale_factor = get_scale(map);
	map->scale.x = (map->width_x * map->scale_factor) / 2;
	map->scale.y = (map->length_y * map->scale_factor) / 2;
	while (i < map->width_x)
	{
		j = 0;
		while (j < map->length_y)
		{
			map->coord[i][j].x = i * map->scale_factor - map->scale.x;
			map->coord[i][j].y = j * map->scale_factor - map->scale.y;
			map->coord[i][j].z = map->coord[i][j].z * map->scale_factor * 0.1;
			//set_isometric(map, i, j);
			map->coord[i][j].x += map->center_x;
			map->coord[i][j].y += map->center_y;
			j++;
		}
		i++;
	}
} */
