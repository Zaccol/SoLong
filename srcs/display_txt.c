/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_txt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:19:50 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/10 21:11:56 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	wright_txt(char c, t_data mlx, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.wall.img, (mlx.txt.wall.w * j), (mlx.txt.wall.h * i));
	else if (c == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.floor.img, (mlx.txt.floor.w * j), (mlx.txt.floor.h * i));
	else if (c == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.player.img, (mlx.txt.player.w * j), (mlx.txt.player.h * i));
	else if (c == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.exit.img, (mlx.txt.exit.w * j), (mlx.txt.exit.h * i));
	else if (c == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.collect.img, (mlx.txt.collect.w * j), (mlx.txt.collect.h * i));
}

void	put_txt(char **map, t_data mlx, t_stuff stuff)
{
	(void)mlx;
	int i;
	int j;

	i = 0;
	while (i < stuff.line_count)
	{
		j = 0;
		while (j < stuff.line_len)
		{
			wright_txt(map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
}

void	display_map(char **map, t_stuff stuff)
{
	t_data mlx;
	t_combo combo;
	combo.map = map;
	combo.stuff = &stuff;
	combo.count = 0;
	// mlx.x = 0;
	// mlx.y = 0;
	// int height;
	// int width;
	// char *path = "textures/floor.xpm";

	mlx.mlx = mlx_init();
	get_txt(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, (mlx.txt.floor.w * stuff.line_len), (mlx.txt.floor.h * stuff.line_count), "So Long !");
	// init_txt(&mlx, &mlx.txt.floor, FLOOR);
	// mlx.img = mlx_xpm_file_to_image(mlx.mlx, path, &height, &width);
	// mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 64, 64);
	// mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.floor.img, 0, 0);
	put_txt(map, mlx, stuff);
	// mlx_hook(mlx.win, 2, 1L<<17, ft_close, &mlx);
	combo.mlx = &mlx;
	mlx_hook(mlx.win, 17, 0L, &ft_cross, &mlx);
	mlx_hook(mlx.win, 2, 1L<<0, direction, &combo);
	mlx_loop(mlx.mlx);
}