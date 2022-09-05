/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:31:03 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/03 05:01:28 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_fdf(int argc, char *argv)
{
	if (argc != 2)
		error(1);
	if (open(argv, O_RDONLY) == -1)
		error(2);
}

void	is_map(char *file, t_map *map)
{
	int	x;
	int	y;
	x = get_width(file);
	y = get_length(file);
	if (!x || !y)
		exit(EXIT_SUCCESS);
	//SET_MAP
	map->width_x = x;
	map->length_y = y;
}

void init_interface(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error(3);
	data->win_ptr = mlx_new_window(data->mlx_ptr, MLX_WIDTH, MLX_HEIGHT, MLX_TITLE);
	if (!data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		error(4);
	}
	data->map.center_x = MLX_WIDTH / 2;
	data->map.center_y = MLX_HEIGHT / 2;
	data->map.std_zoom = 0;
	data->map.std_scale = get_scale(&data->map);
	//SET USER VALUES
	data->map.scale_factor = data->map.std_scale;
	data->map.std_zoom = data->map.usr_z_axis;
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	init_fdf(argc, argv[1]);
	is_map(argv[1], &data.map);
	instance_map(&data.map);
	data.map.coord = instance_coord(data.map.width_x, data.map.length_y);
	if (!data.map.coord)
		return (0);
	fill_axes(argv[1], &data.map); //THIRD PARAMETER FOR PROJECTION ?
	init_interface(&data);
	//set_map(argv[1], &data.map);
	//fit_map(&data.map);
	create_image(&data);

	mlx_expose_hook(data.win_ptr, &create_image, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &quit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
