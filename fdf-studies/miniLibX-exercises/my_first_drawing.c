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

#define WIDTH 500
#define HEIGHT 500
#define MLX_ERROR 1
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	//What variable is this?
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
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

void	render_background(t_img *img, int color)
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
}

int	render(t_data *data)
{
	//Puts a pixel on window
	/* if (data->win_ptr != NULL)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			WIDTH / 2, HEIGHT / 2, RED_PIXEL); */
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){WIDTH - 100, HEIGHT - 100,
			100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		perror("Error");
		return (MLX_ERROR);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "mlx 42");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		perror("Error");
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
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
	//mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}