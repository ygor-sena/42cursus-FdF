/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:33:03 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/05 16:26:31 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	render_line(t_img *img, t_point start, t_point end, t_map *map);
void	set_stroke(t_point start, t_point end, t_stroke *line);
void	check_color(t_point *point);

void	set_map(t_map *map, t_point *point, int i, int j)
{
	//int tmpx;
	point->x = i * map->scale_factor - map->scale.x + map->transl_x;
	point->y = j * map->scale_factor - map->scale.y + map->transl_y;
	point->z = map->coord[i][j].z * map->scale_factor * 0.1 * map->usr_z_axis;
	point->color = map->coord[i][j].color;
	if (map->projection == ISOMETRIC)
		set_isometric(point);
	//tmpx = point->x;
	//point->x = map->rotation.Axx * tmpx + map->rotation.Axy*point->y + map->rotation.Axz*point->z;
	point->x += map->center_x;
	point->y += map->center_y;
}

int	create_image(t_fdf *data)
{
	int	i;
	int	j;
	t_point	p1;
	t_point	p2;

	//CREATE NEW IMAGE
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, MLX_WIDTH, MLX_HEIGHT);
	
	/* [SETUP HOOKS] */
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->win_ptr)
		return (1);
	i = 0;
	//RENDER/DRAW
	data->map.scale.x = (data->map.width_x * data->map.scale_factor) / 2;
	data->map.scale.y = (data->map.length_y * data->map.scale_factor) / 2;
	while (i < data->map.width_x)
	{
		j = 0;
		while (j < data->map.length_y)
		{
			set_map(&data->map, &p1, i, j);
			if (j + 1 < data->map.length_y)
			{
				set_map(&data->map, &p2, i, j + 1);
				/* render_line(&data->img, &data->map.coord[i][j], \
						&data->map.coord[i][j + 1], &data->map); */
				render_line(&data->img, p1, p2, &data->map);
			}	
			if (i + 1 < data->map.width_x)
			{
				set_map(&data->map, &p2, i + 1, j);
				/* render_line(&data->img, &data->map.coord[i][j], \
						&data->map.coord[i + 1][j], &data->map); */
				render_line(&data->img, p1, p2, &data->map);
			}	
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->img.mlx_img, 0, 0);
	//DESTROY IMAGE
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
}

void	render_line(t_img *img, t_point start, t_point end, t_map *map)
{
	t_stroke	line;

	if (map->is_colored == FALSE)
	{
		check_color(&start);
		check_color(&end);
	}
	set_stroke(start, end, &line);
	bresenham(img, line);
}

void	set_stroke(t_point start, t_point end, t_stroke *line)
{
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->gap_x = end.x + start.x;
	//ft_abs((end->x - start->x) + (end->y + start->y));
	line->gap_y = end.y + start.y;
}

void	check_color(t_point *point)
{
	if (point->z == 0)
		point->color = ft_atoi_base(WHITE_PIXEL, LOW_HEX_BASE);
	else
		point->color = ft_atoi_base(BLUE_PIXEL, LOW_HEX_BASE);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ((x < 0 || x >= MLX_WIDTH) || (y < 0 || y >= MLX_HEIGHT))
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

/* void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
} */

/* 
if (j + 1 < data->map.length_y)
			{
				line = set_stroke(data->map.coord[i][j], data->map.coord[i][j + 1]);
				render_line(&data->img, data->map.coord[i][j], data->map.coord[i][j + 1]);
			}
			if (i + 1 < data->map.width_x)
			{
				line = set_stroke(data->map.coord[i][j], data->map.coord[i + 1][j]);
				render_line(&data->img, line);
			}
 */
