/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:13:41 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/27 21:43:05 by ael-khni         ###   ########.fr       */
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
# include <math.h>
# include "mlx.h"

# define EQUAL 0

/* -------- KEY VALUES -------- */
# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
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
	int			col;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*filename;
	char		starting_pos;
	t_color		floor_color;
	t_color		ceilling_color;
	t_vector	player;
}	t_map;

typedef struct s_img
{
	void	*ptr;
	int		len;
	int		bpp;
	int		endian;
	int		*arr;
	int		width;
	int		height;
}	t_img;

typedef struct s_program
{
	void		*mlx;
	void		*win_ptr;
	char		**cub_content;
	t_map		map;
	t_img		img;
	t_img		tex;
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
	double		m_speed;
	double		r_angle;
	double		wallx;
	double		tex_pos;
	double		tex_step;
	int			r_right;
	int			m_right;
	int			r_left;
	int			m_left;
	int			m_up;
	int			m_down;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			x;
	int			tex_x;
	int			tex_y;
	int			screen_w;
	int			screen_h;
}				t_program;

int		lunch_game(void *ptr);

/* ---- Utils Functions ---- */
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *str, char *sap);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strndup(char *s1, int n);
void	ft_puterror(char *msg);

/* ---- Parser Functions ---- */
int		nbr_of_lines(char *filename);
void	get_cub_content(t_program *ptr);
void	check_cub_content(char **content);
void	print_map(t_map map);
void	get_map_textures(t_program *game_ptr);
void	get_rgb(t_color *color, char **str);
void	get_colors(t_program *ptr);
void	get_map(t_program *ptr);
int		get_map_len(t_program *ptr);
void	get_player_pos(t_map *map);
void	parse_map(t_program *ptr);
int		check_north_wall(char **map, int row, int col);
int		check_south_wall(char **map, int row, int col);
int		check_east_wall(char **map, int row, int col);
int		check_west_wall(char **map, int row);
int		check_wall(char **map, int row, int col);
int		check_extended_wall(char **map, int row);
int		check_player_surroundings(char **map, int row, int col);
void	check_map(char **map);
void	map_checks_(t_map map, int row, int col);
void	check_map_full(t_map map);
int		in_charset(char c, char *set);
int		check_new_line(char *str);
void	free_split(char **tab);
int		check_extention(char *src, char *to_find);
void	check_cub_texture(char **content, int *i);
void	check_cub_colors(char **content, int *i);
void	check_cub_content(char **content);

/* ---- Init Functions ---- */
void	init_map(t_map *map);
void	init_game(t_program *game);

//free
void	ft_free(t_program *game, char *msg);
int		ft_close(t_program *game);

/* ---- KEY_HOOKS Functions ---- */
int		press(int key, t_program *game_ptr);
int		release(int key, t_program *game_ptr);
void	move(t_program *game_ptr);

/* ---- MOVES Functions ---- */
void	rotate(t_program *game_ptr, double angle);
void	forword(t_program *game_ptr);
void	backword(t_program *game_ptr);
void	right(t_program *game_ptr);
void	left(t_program *game_ptr);

void	start_game(t_program *game);

void	draw_floor_ceiling(t_program *game_ptr);
void	init_draw_var(t_program *game_ptr);
void	raycast(t_program *game_ptr);
void	calc_distance(t_program *game_ptr);
int		rgb_to_int(t_color color);
void	ft_new_window(t_program *game);
void	draw(t_program *game_ptr);

/* ---- TEX Functions ---- */
void	get_tex(t_program *game_ptr);
void	init_tex(t_program *game_ptr);
void	put_tex(t_program *game_ptr);

#endif
