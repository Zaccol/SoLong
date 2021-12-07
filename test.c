#include "includes/so_long.h"

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_data;

// int	ft_close(int keycode, t_data *mlx)
// {
// 	printf("%i\n", keycode);
	
// 	return (0);
// }
void	free_mlx(t_data *mlx)
{
	if (mlx->mlx)
		{
			mlx_destroy_image(mlx->mlx, mlx->img);
			mlx_destroy_window(mlx->mlx, mlx->win);
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
		}
	exit(0);
}

int	ft_cross(t_data *mlx)
{
	free_mlx(mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render_next_frame(t_data *mlx)
{
	my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00FF0000);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	direction(int keycode, t_data *mlx)
{
	if (keycode == 65307)
		free_mlx(mlx);
	if (keycode == 100)
	{
		mlx->x++;
		return (0);
	}
	if (keycode == 119)
	{
		mlx->y--;
		return (0);
	}
	if (keycode == 97)
	{
		mlx->x--;
		return (0);
	}
	if (keycode == 115)
	{
		mlx->y++;
		return (0);
	}
	return (0);
}

int	main(void)
{
	t_data mlx;
	mlx.x = 5;
	mlx.y = 5;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "So Long !");
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	// mlx_hook(mlx.win, 2, 1L<<17, ft_close, &mlx);
	mlx_hook(mlx.win, 17, 0L, &ft_cross, &mlx);
	mlx_hook(mlx.win, 2, 1L<<0, direction, &mlx);
	mlx_loop_hook(mlx.mlx, render_next_frame, &mlx);
	mlx_loop(mlx.mlx);
}