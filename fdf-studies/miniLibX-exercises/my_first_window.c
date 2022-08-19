#include "mlx.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500
#define MLX_ERROR 1

int	deal_key(int key, void *param)
{
	static int nbr = 0;

	nbr++;
	printf("%d : %d\n", nbr, key);
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		free(mlx_ptr);
		perror("Error");
		return (MLX_ERROR);
	}
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "mlx 42");
	if (!win_ptr)
	{
		free(win_ptr);
		perror("Error");
		return (MLX_ERROR);
	}
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
