/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:21:30 by lzaccome          #+#    #+#             */
/*   Updated: 2021/12/01 06:14:45 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_stuff 
{
	int line_count;
	int line_len;
	int player;
	int collectible;
	int exit;
} t_stuff;

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

/* -------------------------------------------------------------------------- */
/*                              FILE = ./error.c                              */
/* -------------------------------------------------------------------------- */
void	error(void);
void	free_map(char **map, int line_count);
void	free_map_exit(char **map, int line_count, char *message);
void	error_message(char *message);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./utils.c                              */
/* -------------------------------------------------------------------------- */
void	ft_putstr(char *str);

#endif