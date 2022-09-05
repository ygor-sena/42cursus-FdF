/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:32:01 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/05 16:26:44 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//MARCELO MAGALHAES TM LTDA
int	quit(t_fdf *data)
{
	//void close_fdf(t_fdf *data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free_coord(data->map.coord, data->map.width_x);
	free(data->mlx_ptr);
	//Set to NULL to avoid memory leak/trash data
	//data->win_ptr = NULL;
	exit(EXIT_SUCCESS);
}

int zoom_projection(int keysym, t_map *map)
{	
	if (keysym == XK_minus)
		map->scale_factor = map->scale_factor - 1;
	else
		map->scale_factor = map->scale_factor + 1;
	
	return (0);
}

int change_projection(int keysym, t_map *map)
{
	if (keysym == 111)
		map->projection = ORTHOGRAFIC;
	else
		map->projection = ISOMETRIC;
	return(0);
}

int change_z(int keysym, t_map *map)
{
	if (keysym == 122)
	{
		printf("Z AXIS %d", map->usr_z_axis);
		map->usr_z_axis = map->usr_z_axis + 1;
	}
	else
		map->usr_z_axis = map->usr_z_axis - 1;
	return(0);
}

/* # define XK_KP_Left                       0xff96
# define XK_KP_Up                         0xff97
# define XK_KP_Right                      0xff98
# define XK_KP_Down                       0xff99 */

void transl_isometric(int keysym, t_map *map)
{
	if (keysym == 65362) //UP
	{
		map->transl_x = map->transl_x - 5;
		map->transl_y = map->transl_y - 5;
	}
	else if (keysym == 65364) //DOWN
	{
		map->transl_x = map->transl_x + 5;
		map->transl_y = map->transl_y + 5;
	}
	else if (keysym == 65363) //RIGHT
	{
		map->transl_y = map->transl_y - 5;
		map->transl_x = map->transl_x + 5;
	}
	else
	{
		map->transl_y = map->transl_y + 5;
		map->transl_x = map->transl_x - 5;
	}
}

void transl_orthographic(int keysym, t_map *map)
{
	if (keysym == 65362) //UP
		map->transl_y = map->transl_y - 5;
	else if (keysym == 65364) //DOWN
		map->transl_y = map->transl_y + 5;
	else if (keysym == 65363) //RIGHT
		map->transl_x = map->transl_x + 5;
	else
		map->transl_x = map->transl_x - 5;
}

int translate_projection(int keysym, t_map *map)
{
	if (map->projection == ORTHOGRAFIC)
		transl_orthographic(keysym, map);
	else
		transl_isometric(keysym, map);
	return (0);
}

/* int rotate_x(t_map *map)
{
	map->roll_x = map->roll_x + 0.1;
	int	alpha_cos = cos(COSINE_30 + map->roll_x);
	int	alpha_sin = sin(SINE_30 + map->roll_x);
	int	beta_cos = cos(COSINE_30 + map->pitch_y);
	int	beta_sin = sin(SINE_30 + map->pitch_y);
	int	gamma_cos = cos(COSINE_30 + map->yaw_z);
	int	gamma_sin = sin(SINE_30 + map->yaw_z);

	map->rotation.Axx = alpha_cos*beta_cos;
    map->rotation.Axy = alpha_cos*beta_sin*gamma_sin - alpha_sin*gamma_cos;
    map->rotation.Axz = alpha_cos*beta_sin*gamma_cos + alpha_sin*gamma_sin;
	return (0);
}

int rotate_projection(int keysym, t_map *map)
{
	if (keysym == 91)
		rotate_x(map);
	return (0);
}
 */


/* function rotate(pitch, roll, yaw) {
    var cosa = Math.cos(yaw);
    var sina = Math.sin(yaw);

    var cosb = Math.cos(pitch);
    var sinb = Math.sin(pitch);

    var cosc = Math.cos(roll);
    var sinc = Math.sin(roll);

    var Axx = cosa*cosb;
    var Axy = cosa*sinb*sinc - sina*cosc;
    var Axz = cosa*sinb*cosc + sina*sinc;

    var Ayx = sina*cosb;
    var Ayy = sina*sinb*sinc + cosa*cosc;
    var Ayz = sina*sinb*cosc - cosa*sinc;

    var Azx = -sinb;
    var Azy = cosb*sinc;
    var Azz = cosb*cosc;

    for (var i = 0; i < points.length; i++) {
        var px = points[i].x;
        var py = points[i].y;
        var pz = points[i].z;

        points[i].x = Axx*px + Axy*py + Axz*pz;
        points[i].y = Ayx*px + Ayy*py + Ayz*pz;
        points[i].z = Azx*px + Azy*py + Azz*pz;
    }
} */

int	handle_keypress(int keysym, t_fdf *data)
{
	printf("FACTOR BEFORE: %d", data->map.scale_factor);
	if (keysym == XK_Escape)
		quit(data);
	else if (keysym == XK_minus || keysym == XK_equal)
		zoom_projection(keysym, &data->map);
	else if (keysym == 105 || keysym == 111) //O //I
		change_projection(keysym, &data->map);
	//LEFT
	else if (keysym == 65361 || keysym == 65363 || keysym == 65364 || keysym == 65362)
		translate_projection(keysym, &data->map);
	else if (keysym == 114) //R
	{
		data->map.center_x = MLX_WIDTH / 2;
		data->map.center_y = MLX_HEIGHT / 2;
		data->map.std_zoom = 0;
		data->map.std_scale = get_scale(&data->map);
		//SET USER VALUES
		data->map.scale_factor = data->map.std_scale;
		data->map.projection = ISOMETRIC;
		data->map.usr_z_axis = 1;
		data->map.std_zoom = data->map.usr_z_axis;
		data->map.transl_x = 0;
		data->map.transl_y = 0;
		/* data->map.rotation.Axx =  0;
		data->map.rotation.Axy = 0;
		data->map.rotation.Axz = 0; */
	}
	else if (keysym == 122 || keysym == 120) //z //x
		change_z(keysym, &data->map);
	/* else if (keysym == 97 || keysym == 115 || keysym == 115) //A, S, D
		rotate_projection(keysym, &data->map); */
	
		
	printf("Keypress: %d\n", keysym);
	//fit_map(&data->map);
	create_image(data);
	return (0);
}


