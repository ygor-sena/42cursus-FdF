/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:31:03 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 20:47:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_fdf(int argc, char *argv);
static void	is_map(char *file, t_map *map);
static void	init_interface(t_fdf *data);

int	main(int argc, char **argv)
{
	t_fdf	data;

	init_fdf(argc, argv[1]);
	instance_map(&data.map);
	is_map(argv[1], &data.map);
	data.map.coord = instance_coord(data.map.width_x, data.map.length_y);
	if (!data.map.coord)
	{
		perror(INVALID_MEMORY);
		exit(EXIT_FAILURE);
	}
	init_interface(&data);
	get_file_content(argv[1], &data.map);
	create_image(&data);
	mlx_expose_hook(data.win_ptr, &create_image, &data);
	mlx_hook(data.win_ptr, KEYPRESS, KEYPRESSMASK, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DESTROYNOTIFY, NOEVENTMASK, &quit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

static void	init_fdf(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf(INVALID_ARGS);
		exit(EXIT_FAILURE);
	}
	if (open(argv, O_RDONLY) == -1)
	{
		perror(INVALID_FILE);
		exit(EXIT_FAILURE);
	}
}

static void	is_map(char *file, t_map *map)
{
	if (!get_file_dimension(file, map))
	{
		perror(INVALID_FILE);
		exit(EXIT_FAILURE);
	}
}

static void	init_interface(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror(ERROR_MLX);
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window
		(data->mlx_ptr, MLX_WIDTH, MLX_HEIGHT, MLX_TITLE);
	if (!data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		perror(ERROR_WIN);
		exit(EXIT_FAILURE);
	}
	data->map.center_x = MLX_WIDTH / 2;
	data->map.center_y = MLX_HEIGHT / 2;
	data->map.std_zoom = 0;
	data->map.std_scale = get_scale(&data->map);
	data->map.scale_factor = data->map.std_scale;
	data->map.std_zoom = data->map.usr_z_axis;
}
