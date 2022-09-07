/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_first_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:31:03 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/01 19:05:48 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
/* This is to get the values (key code) of all 
		the available symbols (key symbols) */
#include <X11/keysym.h>
/* This lib is for the Key Tags of mlx_hook! */
#include <X11/X.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define MLX_ERROR 1
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define ORANGE_PIXEL 0xFCC203
#define BLUE_PIXEL 0x033DFC
#define LOW_HEX_BASE "0123456789abcdef"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	int		color;
}	t_line;

t_point	set_point(int x, int y, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.color = color;
	return (point);
}

void	bresenham(t_img *img, t_line line);

int	render_line(t_img *img, t_line line)
{
	
	bresenham(img, line);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		//Set to NULL to avoid memory leak/trash data
		data->win_ptr = NULL;
	}
	printf("Keypress: %d\n", keysym);
	return (0);
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
int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	int area;
	int	scale;
	area = (HEIGHT * WIDTH) / 4;
	scale = sqrt(area / (10 + 15));
	/* i = (WIDTH * 0.25) / 7;
	H = U*(Nr+Nc)/2 */
	//i = ((10 + 5)* WIDTH) * 0.5;
	
	render_line(&data->img, (t_line){set_point(0, 0, 255), set_point(400, 400, 16711680), 0});
	//render_line(&data->img, (t_line){set_point(0, 100), set_point(scale, 100), WHITE_PIXEL});
	/* render_line(&data->img, (t_line){set_point(100, 100), set_point(400, 100), WHITE_PIXEL});
	render_line(&data->img, (t_line){set_point(100, 400), set_point(400, 400), WHITE_PIXEL});
	render_line(&data->img, (t_line){set_point(100, 100), set_point(100, 400), WHITE_PIXEL});

	render_line(&data->img, (t_line){set_point(250, 250), set_point(100, 200), BLUE_PIXEL});
	render_line(&data->img, (t_line){set_point(250, 250), set_point(200, 100), RED_PIXEL});
	render_line(&data->img, (t_line){set_point(250, 250), set_point(100, 100), GREEN_PIXEL});

	render_line(&data->img, (t_line){set_point(250, 250), set_point(300, 400), GREEN_PIXEL});
	render_line(&data->img, (t_line){set_point(250, 250), set_point(400, 300), RED_PIXEL});
	render_line(&data->img, (t_line){set_point(250, 250), set_point(400, 400), ORANGE_PIXEL});

	render_line(&data->img, (t_line){set_point(100, 400), set_point(250, 250), RED_PIXEL});
	render_line(&data->img, (t_line){set_point(400, 100), set_point(250, 250), BLUE_PIXEL});

	render_line(&data->img, (t_line){set_point(250, 250), set_point(100, 300), GREEN_PIXEL});
	render_line(&data->img, (t_line){set_point(250, 250), set_point(300, 100), ORANGE_PIXEL});
	render_line(&data->img, (t_line){set_point(250, 250), set_point(400, 200), ORANGE_PIXEL});
	render_line(&data->img, (t_line){set_point(250, 250), set_point(200, 400), BLUE_PIXEL}); */

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		perror("Error");
		return (MLX_ERROR);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "album indie");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		perror("Error");
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	/* [SETUP HOOKS] */
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	/* This function executes actions without events happening.
			It can be used for drawing things, i.e. a FdF map.
			Also, it must be used if mlk_loop is called, because
			that's the way they were implemented. */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	/* This is a RELEASE function. It doesn't implement
			the PRESSED event */
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	/* Keeps window running */
	mlx_loop(data.mlx_ptr);

	/* Destroy and free everything that was allocated 
			after there is no windows left */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
