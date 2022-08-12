#include <mlx.h>
/* This is to get the values (key code) of all 
		the available symbols (key symbols) */
#include <X11/keysym.h>
/* This lib is for the Key Tags of mlx_hook! */
#include <X11/X.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500
#define MLX_ERROR 1
#define RED_PIXEL 0xFF0000

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			WIDTH / 2, HEIGHT / 2, RED_PIXEL);
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
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	/* [SETUP HOOKS] */
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
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}