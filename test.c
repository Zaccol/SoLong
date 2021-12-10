#include "includes/so_long.h"

#define FLOOR	"textures/floor.xpm"
#define WALL	"textures/wall.xpm"
#define PLAYER	"textures/player.xpm"
#define COLLECT	"textures/collect.xpm"
#define EXIT	"textures/exit.xpm"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}				t_img;

typedef struct s_txt {
	t_img	floor;
	t_img	wall;
	t_img	collect;
	t_img	exit;
	t_img	player;
}				t_txt;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_txt	txt;
	int		x;
	int		y;
}				t_data;

// typedef struct s_img {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }

int	ft_close(int keycode, t_data *mlx)
{
	printf("%i\n", keycode);
	return (0);
}
void	free_mlx(t_data *mlx)
{
	if (mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->txt.floor.img);
		// mlx_destroy_image(mlx->mlx, mlx->txt.wall.img);
		// mlx_destroy_image(mlx->mlx, mlx->txt.player.img);
		// mlx_destroy_image(mlx->mlx, mlx->txt.collect.img);
		// mlx_destroy_image(mlx->mlx, mlx->txt.exit.img);
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

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	render_next_frame(t_data *mlx)
// {
// 	my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00FF0000);
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
// 	return (0);
// }

int	direction(int keycode, t_data *mlx)
{
	if (keycode == 65307)
		free_mlx(mlx);
	if (keycode == 100 && mlx->x < 1920 )
	{
		mlx->x++;
		// my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00FF0000);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, mlx->x, mlx->y);
		return (0);
	}
	if (keycode == 119 && mlx->y > 0)
	{
		mlx->y--;
		// my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00FF0000);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, mlx->x, mlx->y);
		return (0);
	}
	if (keycode == 97 && mlx->x > 0)
	{
		mlx->x--;
		// my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00FF0000);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, mlx->x, mlx->y);
		return (0);
	}
	if (keycode == 115 && mlx->y < 1080)
	{
		mlx->y++;
		// my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x00FF0000);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, mlx->x, mlx->y);
		return (0);
	}
	return (0);
}

void	init_txt(t_data *mlx, t_img *txt, char *path)
{
	txt->img = mlx_xpm_file_to_image(mlx->mlx, path, &txt->h, &txt->w);
}

void	get_txt(t_data *mlx)
{
	init_txt(mlx, &mlx->txt.floor, FLOOR);
	init_txt(mlx, &mlx->txt.wall, WALL);
	init_txt(mlx, &mlx->txt.player, PLAYER);
	init_txt(mlx, &mlx->txt.collect, COLLECT);
	init_txt(mlx, &mlx->txt.exit, EXIT);
}

int	main(void)
{
	t_data mlx;
	// mlx.x = 0;
	// mlx.y = 0;
	// int height;
	// int width;
	// char *path = "textures/floor.xpm";

	mlx.mlx = mlx_init();
	get_txt(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, mlx.txt.floor.w, mlx.txt.floor.h, "So Long !");
	// init_txt(&mlx, &mlx.txt.floor, FLOOR);
	// mlx.img = mlx_xpm_file_to_image(mlx.mlx, path, &height, &width);
	// mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 64, 64);
	// mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.floor.img, 0, 0);
	// mlx_hook(mlx.win, 2, 1L<<17, ft_close, &mlx);
	mlx_hook(mlx.win, 17, 0L, &ft_cross, &mlx);
	// mlx_hook(mlx.win, 2, 1L<<0, direction, &mlx);
	mlx_loop(mlx.mlx);
}