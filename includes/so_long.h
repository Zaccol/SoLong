/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:21:30 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/11 20:58:33 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

/* -------------------------------------------------------------------------- */
/*                                     MLX                                    */
/* -------------------------------------------------------------------------- */

# define FLOOR	"textures/floor.xpm"
# define WALL	"textures/wall.xpm"
# define PLAYER	"textures/player.xpm"
# define COLLECT	"textures/collect.xpm"
# define EXIT	"textures/exit.xpm"

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

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_txt	txt;
	int		x;
	int		y;
}				t_data;

/* -------------------------------------------------------------------------- */
/*                                     PARSING                                */
/* -------------------------------------------------------------------------- */

typedef struct s_stuff
{
	int	line_count;
	int	line_len;
	int	player;
	int	collectible;
	int	exit;
	int	x;
	int	y;
}				t_stuff;

typedef struct s_combo {
	t_data	*mlx;
	t_stuff	*stuff;
	char	**map;
	int		count;
}				t_combo;

/* -------------------------------------------------------------------------- */
/*                              FILE = ./parse.c                              */
/* -------------------------------------------------------------------------- */
int		is_wrong_elem(char c, t_stuff *stuff, int i, int j);
void	verif_map(char **map, t_stuff *stuff);
void	parse_map(char **map, t_stuff *stuff);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./gnl_utils.c                          */
/* -------------------------------------------------------------------------- */
int		ft_strclen(char *s, char c);
char	*ft_strcdup(char *s, char c);
int		ft_strlen(char *str);
char	*ft_strcjoin(char *s1, char *s2, char c);
char	*ft_strchr(char *s, char c);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./get_next_line.c                      */
/* -------------------------------------------------------------------------- */
int		strchr_backslash(char *buf, int loop);
void	shift_str(char *str);
char	*get_next_line(int fd);
void	free_line(char *line);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./error.c                              */
/* -------------------------------------------------------------------------- */
void	error(void);
void	free_map(char **map, int line_count);
void	free_map_exit(char **map, int line_count, char *message);
void	free_map_exit2(char **map, int line_failed, char *message);
void	error_message(char *message);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./utils.c                              */
/* -------------------------------------------------------------------------- */
void	ft_putstr(char *str);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./display_txt.c                        */
/* -------------------------------------------------------------------------- */
void	free_mlx(t_data *mlx, char **map, int line_count);
int		ft_cross(t_combo *combo);
void	init_txt(t_data *mlx, t_img *txt, char *path);
void	get_txt(t_data *mlx);
void	display_map(char **map, t_stuff stuff);
int		ft_close(int keycode, t_data *mlx);
void	put_txt(char **map, t_data mlx, t_stuff stuff);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./init_txts.c                          */
/* -------------------------------------------------------------------------- */
void	get_txt(t_data *mlx);
void	wright_txt(char c, t_data mlx, int i, int j);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./direction.c                          */
/* -------------------------------------------------------------------------- */
int		direction(int keycode, t_combo *combo);
void	move_right(t_combo *combo);
void	move_up(t_combo *combo);
void	move_left(t_combo *combo);
void	move_down(t_combo *combo);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./win.c                                */
/* -------------------------------------------------------------------------- */
int		win_cond_right(t_combo *combo);
int		win_cond_up(t_combo *combo);
int		win_cond_left(t_combo *combo);
int		win_cond_dowm(t_combo *combo);

#endif