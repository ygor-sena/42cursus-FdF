/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:33:03 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 23:27:49 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_img_data(t_fdf *data);
static void	init_map_plot(t_fdf *data, t_point *p1, t_point *p2);

int	create_image(t_fdf *data)
{
	t_point	p1;
	t_point	p2;

	init_img_data(data);
	init_map_plot(data, &p1, &p2);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
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

static void	init_img_data(t_fdf *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, MLX_WIDTH, MLX_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->win_ptr)
	{
		perror(ERROR_WIN);
		quit(data);
		exit(EXIT_FAILURE);
	}
	data->map.scale.x = (data->map.width_x * data->map.scale_factor) / 2;
	data->map.scale.y = (data->map.length_y * data->map.scale_factor) / 2;
}

static void	init_map_plot(t_fdf *data, t_point *p1, t_point *p2)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.width_x)
	{
		j = 0;
		while (j < data->map.length_y)
		{
			set_map(data, p1, i, j);
			if (j + 1 < data->map.length_y)
			{
				set_map(data, p2, i, j + 1);
				bresenham(&data->img, p1, p2);
			}	
			if (i + 1 < data->map.width_x)
			{
				set_map(data, p2, i + 1, j);
				bresenham(&data->img, p1, p2);
			}
			j++;
		}
		i++;
	}
}
