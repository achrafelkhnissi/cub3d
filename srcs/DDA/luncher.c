#include "cub3d.h"

void	ext_init_draw(t_program *game_ptr)
{
		if (game_ptr->raydir_x < 0)
		{
			game_ptr->step_x = -1;
			game_ptr->side_dist_x = (game_ptr->pos_x - game_ptr->map_x) * game_ptr->delta_dist_x;
		}
		else 
		{
			game_ptr->step_x = 1;
			game_ptr->side_dist_x = (game_ptr->map_x + 1.0 - game_ptr->pos_x) * game_ptr->delta_dist_x;
		}
		if (game_ptr->raydir_y < 0)
		{
			game_ptr->step_y = -1;
			game_ptr->side_dist_y = (game_ptr->pos_y - game_ptr->map_y) * game_ptr->delta_dist_y;
		}
		else 
		{
			game_ptr->step_y = 1;
			game_ptr->side_dist_y = (game_ptr->map_y + 1.0 - game_ptr->pos_y) * game_ptr->delta_dist_y;
		}
}

void	init_draw_var(t_program *game_ptr)
{
		game_ptr->camera_x = 2 * (game_ptr->x / (double)(game_ptr->screen_w)) - 1;
		game_ptr->raydir_x = game_ptr->dir_x + game_ptr->plane_x * game_ptr->camera_x;
		game_ptr->raydir_y = game_ptr->dir_y + game_ptr->plane_y * game_ptr->camera_x;
		game_ptr->map_x = (int)game_ptr->pos_x;
		game_ptr->map_y = (int)game_ptr->pos_y;
		printf("px: %f, py: %f\n", game_ptr->pos_x, game_ptr->pos_y);
		printf("x: %i, y: %i\n", game_ptr->map_x, game_ptr->map_y);
		game_ptr->delta_dist_x = sqrt(1 + pow(game_ptr->raydir_y, 2) / pow(game_ptr->raydir_x, 2));
		game_ptr->delta_dist_y = sqrt(1 + pow(game_ptr->raydir_x, 2) / pow(game_ptr->raydir_y, 2));
		game_ptr->hit = 0;
		ext_init_draw(game_ptr);
}

void	raycast(t_program *game_ptr)
{
		while (game_ptr->hit == 0)
		{
			if (game_ptr->side_dist_x < game_ptr->side_dist_y)
			{
				game_ptr->side_dist_x += game_ptr->delta_dist_x;
				game_ptr->map_x += game_ptr->step_x;
				game_ptr->side = 0;
			}
			else
			{
				game_ptr->side_dist_y += game_ptr->delta_dist_y;
				game_ptr->map_y += game_ptr->step_y;
				game_ptr->side = 1;	
			}
			if (game_ptr->map.map[game_ptr->map_x][game_ptr->map_y] == '1') 
				game_ptr->hit = 1;
		}
		if (game_ptr->side == 0)
			game_ptr->perp_wall_dist = fabs((game_ptr->map_x - game_ptr->pos_x + (1 - game_ptr->step_x) / 2) / game_ptr->raydir_x);
		else
			game_ptr->perp_wall_dist = fabs((game_ptr->map_y - game_ptr->pos_y + (1 - game_ptr->step_y) / 2) / game_ptr->raydir_y);
				printf("p: %f\n", game_ptr->perp_wall_dist);
}

void	calc_distance(t_program *game_ptr)
{
		if (!game_ptr->perp_wall_dist)
			game_ptr->perp_wall_dist = 1;
		game_ptr->line_height = (int)(game_ptr->screen_h / game_ptr->perp_wall_dist);
		game_ptr->draw_start = -game_ptr->line_height / 2 + game_ptr->screen_h  / 2;
		if (game_ptr->draw_start < 0)
			game_ptr->draw_start = 0;
		game_ptr->draw_end =  game_ptr->line_height / 2 + game_ptr->screen_h / 2;
		if (game_ptr->draw_end >= game_ptr->screen_h)
			game_ptr->draw_end = game_ptr->screen_h - 1;
	printf("start: %i, end: %i\n", game_ptr->draw_start, game_ptr->draw_end);
}

void	get_tex(t_program *game_ptr)
{
	if (game_ptr->side == 0 && game_ptr->step_x == -1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, "textures/wood.xpm", &game_ptr->tex.width, &game_ptr->tex.height);
	if (game_ptr->side == 0 && game_ptr->step_x == 1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, "textures/w.xpm", &game_ptr->tex.width, &game_ptr->tex.height);
	if (game_ptr->side == 1 && game_ptr->step_y == -1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, "textures/black-1.xpm", &game_ptr->tex.width, &game_ptr->tex.height);
	if (game_ptr->side == 1 && game_ptr->step_y == 1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, "textures/datacenter.xpm", &game_ptr->tex.width, &game_ptr->tex.height);
}

void	init_tex(t_program *game_ptr)
{
	game_ptr->tex.arr = (int *)mlx_get_data_addr(game_ptr->tex.ptr, &game_ptr->tex.len, &game_ptr->tex.bpp, &game_ptr->tex.endian);
	if (game_ptr->side == 0)
		game_ptr->wallx = game_ptr->pos_y + game_ptr->perp_wall_dist * game_ptr->raydir_y;
	else
		game_ptr->wallx = game_ptr->pos_x + game_ptr->perp_wall_dist * game_ptr->raydir_x;
	 game_ptr->wallx -= (int)((game_ptr->wallx));
	  game_ptr->tex_x = (int)(game_ptr->wallx * (double)(game_ptr->tex.width));
	 if (game_ptr->side == 0 && game_ptr->raydir_x > 0) game_ptr->tex_x = game_ptr->tex.width - game_ptr->tex_x - 1;
	  if (game_ptr->side == 1 && game_ptr->raydir_x < 0) game_ptr->tex_x = game_ptr->tex.width - game_ptr->tex_x - 1;
	game_ptr->tex_step = 1.0 * game_ptr->tex.height / game_ptr->line_height;
	game_ptr->tex_pos = (game_ptr->draw_start - game_ptr->screen_h / 2 + game_ptr->line_height / 2) * game_ptr->tex_step;
}

void	put_tex(t_program *game_ptr)
{
	int y;

	y = game_ptr->draw_start;
	while(y < game_ptr->draw_end)
	{
		game_ptr->tex_y = (int)game_ptr->tex_pos & (game_ptr->tex.height - 1);
		game_ptr->tex_pos += game_ptr->tex_step;
		int *pixel = game_ptr->img.arr + (y * (game_ptr->screen_w) + (game_ptr->x));
		int color = game_ptr->tex.arr[game_ptr->tex.height * game_ptr->tex_y  + game_ptr->tex_x];
		if (game_ptr->side == 1)
		 	color = (color >> 1) & 8355711;
		 *pixel = color;	
		y++;	  
	}
}

void	draw(t_program *game_ptr)
{
	while(game_ptr->x < game_ptr->screen_w)
	{
		init_draw_var(game_ptr);
		raycast(game_ptr);
		calc_distance(game_ptr);
		draw_floor_ceiling(game_ptr);
		get_tex(game_ptr);
		init_tex(game_ptr);
		put_tex(game_ptr);
		game_ptr->x++;
	}
	mlx_put_image_to_window(game_ptr->mlx, game_ptr->win_ptr, game_ptr->img.ptr, 0, 0);
}

int lunch_game(void *ptr)
{
	t_program *game_ptr;

	game_ptr = ptr;
	mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
	draw(game_ptr);
	return 0;
}