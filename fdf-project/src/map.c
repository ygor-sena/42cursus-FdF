/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:50:29 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 21:41:48 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_rotation(t_map *map, t_point *point);
static void	set_isometric(t_point *point);

void	set_map(t_fdf *data, t_point *point, int i, int j)
{
	point->x = i * data->map.scale_factor - data->map.scale.x;
	point->y = j * data->map.scale_factor - data->map.scale.y;
	point->z = data->map.coord[i][j].z
		* data->map.scale_factor * 0.1 * data->map.usr_z_axis;
	point->color = data->map.coord[i][j].color;
	set_rotation(&data->map, point);
	if (data->map.projection == ISOMETRIC)
		set_isometric(point);
	point->x += data->map.center_x + data->map.transl_x;
	point->y += data->map.center_y + data->map.transl_y;
}

int	get_scale(t_map *map)
{
	int	area;
	int	scale;

	area = (MLX_HEIGHT * MLX_WIDTH) / 4;
	scale = sqrt(area / (map->length_y * map->width_x));
	if (scale < 2)
		return (1);
	return (scale);
}

static void	set_isometric(t_point *point)
{
	int	tmp;

	tmp = point->x;
	point->x = (tmp - point->y) * COSINE_30;
	point->y = (tmp + point->y) * SINE_30 - point->z;
}

static void	set_rotation(t_map *map, t_point *point)
{
	int	tmp_x;
	int	tmp_y;

	map->alpha.sin = sin(map->roll_x);
	map->alpha.cos = cos(map->roll_x);
	map->beta.sin = sin(map->pitch_y);
	map->beta.cos = cos(map->pitch_y);
	map->gamma.sin = sin(map->yaw_z);
	map->gamma.cos = cos(map->yaw_z);
	tmp_y = point->y;
	point->y = tmp_y * map->alpha.cos - point->z * map->alpha.sin;
	point->z = tmp_y * map->alpha.sin + point->z * map->alpha.cos;
	tmp_x = point->x;
	point->x = tmp_x * map->beta.cos + point->z * map->beta.sin;
	point->z = -point->y * map->beta.sin + point->z * map->beta.cos;
	tmp_x = point->x;
	point->x = tmp_x * map->gamma.cos - point->y * map->gamma.sin;
	point->y = tmp_x * map->gamma.sin + point->y * map->gamma.cos;
}
