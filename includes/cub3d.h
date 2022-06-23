/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:13:41 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/23 09:58:33 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include "mlx.h"

# define EQUAL 0

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

# define FLOOR "F"
# define CEILLING "C"

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

/* -------- COLORS -------- */
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**map;
	int			row;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*filename; // temp
	char		starting_pos;
	t_color		floor_color;
	t_color		ceilling_color;
	t_vector	player;
}	t_map;

typedef struct s_program
{
	void		*mlx;
	void		*win_ptr;
	void		*img_ptr;
	char		**cub_content;
	t_map		map;
	int			screen_w;
	int			screen_h;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
}				t_program;

int		lunch_game(void *ptr);

/* ---- Utils Functions ---- */
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *str, char *sap);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strndup(char *s1, int n);
void	ft_puterror(char *msg);

/* ---- Parser Functions ---- */
int		nbr_of_lines(char *filename);
void	get_cub_content(t_program *ptr);
void	print_map(t_map map);
void	get_map_textures(t_program *game_ptr);
void	get_colors(t_program *ptr);
void	get_map(t_program *ptr);
void	parse_map(t_program *ptr);
int		check_north_wall(char **map, int row, int col);
int		check_south_wall(char **map, int row, int col);
int		check_east_wall(char **map, int row, int col);
int		check_west_wall(char **map, int row);

/* ---- Init Functions ---- */
void	init_map(t_map *map);
void	init_game(t_program *game);

#endif
