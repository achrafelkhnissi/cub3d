/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:13:41 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/08 06:34:02 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "mlx.h"

/* -------- KEY VALUES -------- */
# define RIGHT_KEY 2
# define LEFT_KEY 0
# define DOWN_KEY 1
# define UP_KEY 13
# define ESC_KEY 53
# define WIN_CLOSE 17

/* -------- MAP -------- */
# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 32

/* -------- COLORS -------- */
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF


typedef struct s_vector
{
	int	x;
	int	y;
} t_vector;

typedef	struct s_map
{
	char	**map;
	int		col;
	int		row;
	t_vector player;
}	t_map;

typedef struct s_program
{
	void		*mlx;
	void		*win_ptr;
	void		*img_ptr;
	// t_map		map;
	int			screen_w;
	int 		screen_h;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		deltaDist_x;
	double		deltaDist_y;
	double		sideDist_x;
	double		sideDist_y;
	double		perpWallDist;
	
}				t_program;

int lunch_game(void *ptr);
#endif
