/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:32:01 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 20:32:10 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	reset_projection(t_fdf *data);

int	handle_keypress(int keysym, t_fdf *data)
{
	if (keysym == KEY_ESC)
		quit(data);
	else if (keysym == KEY_R)
		reset_projection(data);
	else if (keysym == KEY_MINUS || keysym == KEY_EQUAL)
		zoom_projection(keysym, &data->map);
	else if (keysym == KEY_O || keysym == KEY_I)
		change_projection(keysym, &data->map);
	else if (keysym == KEY_UP || keysym == KEY_DOWN \
		|| keysym == KEY_RIGHT || keysym == KEY_LEFT)
		translate_projection(keysym, &data->map);
	else if (keysym == KEY_Z || keysym == KEY_X)
		change_altitude(keysym, &data->map);
	else if (keysym == KEY_A || keysym == KEY_S || keysym == KEY_D \
			|| keysym == KEY_F || keysym == KEY_G || keysym == KEY_H)
		rotate_projection(keysym, &data->map);
	create_image(data);
	return (0);
}

static void	reset_projection(t_fdf *data)
{
	data->map.center_x = MLX_WIDTH / 2;
	data->map.center_y = MLX_HEIGHT / 2;
	data->map.std_zoom = 0;
	data->map.std_scale = get_scale(&data->map);
	data->map.is_colored = FALSE;
	data->map.scale_factor = data->map.std_scale;
	data->map.projection = ISOMETRIC;
	data->map.usr_z_axis = 1;
	data->map.std_zoom = data->map.usr_z_axis;
	data->map.transl_x = 0;
	data->map.transl_y = 0;
	data->map.roll_x = 0;
	data->map.pitch_y = 0;
	data->map.yaw_z = 0;
}

int	quit(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_coord(data->map.coord, data->map.width_x);
	free(data->mlx_ptr);
	data->win_ptr = NULL;
	exit(EXIT_SUCCESS);
}
