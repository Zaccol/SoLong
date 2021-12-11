/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_txt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:19:50 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/11 20:50:21 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_mlx(t_data *mlx, char **map, int line_count)
{
	if (mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->txt.floor.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.wall.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.player.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.collect.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.exit.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free_map(map, line_count);
	exit(0);
}

int	ft_cross(t_combo *combo)
{
	free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	return (0);
}

void	init_txt(t_data *mlx, t_img *txt, char *path)
{
	txt->img = mlx_xpm_file_to_image(mlx->mlx, path, &txt->h, &txt->w);
}

void	put_txt(char **map, t_data mlx, t_stuff stuff)
{
	int	i;
	int	j;

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
	t_data	mlx;
	t_combo	combo;

	combo.map = map;
	combo.stuff = &stuff;
	combo.count = 0;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		free_map(map, stuff.line_count);
		exit(1);
	}
	get_txt(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, (mlx.txt.floor.w * stuff.line_len),
			(mlx.txt.floor.h * stuff.line_count), "So Long !");
	put_txt(map, mlx, stuff);
	combo.mlx = &mlx;
	mlx_hook(mlx.win, 17, 0L, &ft_cross, &combo);
	mlx_hook(mlx.win, 2, 1L << 0, direction, &combo);
	mlx_loop(mlx.mlx);
}
