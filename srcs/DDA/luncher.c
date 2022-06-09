#include "cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};


void	rotate_right(t_program *game_ptr)
{
	double olddirx = game_ptr->dir_x;
	game_ptr->dir_x = game_ptr->dir_x * cos(-0.5) - game_ptr->dir_y * sin(-0.5);
	game_ptr->dir_y = olddirx * sin(-0.5) + game_ptr->dir_y * cos(-0.5);
	double oldplanx = game_ptr->plane_x;
	game_ptr->plane_x = game_ptr->plane_x * cos(-0.5) - game_ptr->plane_y * sin(-0.5);
	game_ptr->plane_y = oldplanx * sin(-0.5) + game_ptr->plane_y * cos (-0.5);
}
void	rotate_left(t_program *game_ptr)
{
	double olddirx = game_ptr->dir_x;
	game_ptr->dir_x = game_ptr->dir_x * cos(0.5) - game_ptr->dir_y * sin(0.5);
	game_ptr->dir_y = olddirx * sin(0.5) + game_ptr->dir_y * cos(0.5);
	double oldplanx = game_ptr->plane_x;
	game_ptr->plane_x = game_ptr->plane_x * cos(0.5) - game_ptr->plane_y * sin(0.5);
	game_ptr->plane_y = oldplanx * sin(0.5) + game_ptr->plane_y * cos (0.5);
}
void forword(t_program * game_ptr)
{
	game_ptr->pos_x += game_ptr->dir_x * 0.5;
	game_ptr->pos_y += game_ptr->dir_y * 0.5;
}

void back(t_program * game_ptr)
{
	game_ptr->pos_x -= game_ptr->dir_x * 0.5;
	game_ptr->pos_y -= game_ptr->dir_y * 0.5;
}

int move(int key, t_program* game_ptr)
{
	if (key == RIGHT_R)
	{
		printf("key:%i\n",key);
		rotate_right(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		drawCeiling(*game_ptr);
		drawFloor(*game_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}
	else if (key == LEFT_R)
	{
		rotate_left(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		drawCeiling(*game_ptr);
		drawFloor(*game_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}
	else if (key == UP_M)
	{
		forword(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		drawCeiling(*game_ptr);
		drawFloor(*game_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);

	}
	else if (key == DOWN_M)
	{
		back(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		drawCeiling(*game_ptr);
		drawFloor(*game_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);

	}
	return 0;
}
int lunch_game( void *ptr)
{
	t_program *game_ptr;
	 
	game_ptr = ptr;

	while (game_ptr->x < game_ptr->screen_w)
	{
		// sleep(1);
		game_ptr->camera_x = 2 * (game_ptr->x / (double)(game_ptr->screen_w)) - 1;
		// printf("cam: %f\n\n", game_ptr->camera_x);
		game_ptr->raydir_x = game_ptr->dir_x + game_ptr->plane_x * game_ptr->camera_x;
		game_ptr->raydir_y = game_ptr->dir_y + game_ptr->plane_y * game_ptr->camera_x;
		game_ptr->map_x = (int)game_ptr->pos_x;
		game_ptr->map_y = (int)game_ptr->pos_y;
		// game_ptr->delta_dist_x = sqrt(1 + (game_ptr->raydir_x * game_ptr->raydir_x) / (game_ptr->raydir_y * game_ptr->raydir_y));
		// game_ptr->delta_dist_y = sqrt(1 + (game_ptr->raydir_y * game_ptr->raydir_y) / (game_ptr->raydir_x * game_ptr->raydir_x));
		game_ptr->delta_dist_x = sqrt(1 + pow(game_ptr->raydir_y, 2) / pow(game_ptr->raydir_x, 2));
		game_ptr->delta_dist_y = sqrt(1 + pow(game_ptr->raydir_x, 2) / pow(game_ptr->raydir_y, 2));
		// game_ptr->delta_dist_x = fabs(1 / game_ptr->raydir_x);
		// game_ptr->delta_dist_y = fabs(1 / game_ptr->raydir_y);
		game_ptr->hit = 0;
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
			if (worldMap[game_ptr->map_x][game_ptr->map_y] > 0) 
				game_ptr->hit = 1;
		}
		if (game_ptr->side == 0)
			game_ptr->perp_wall_dist = game_ptr->side_dist_x - game_ptr->delta_dist_x;
		else
			game_ptr->perp_wall_dist = game_ptr->side_dist_y - game_ptr->delta_dist_y;
		
		// printf("prep: %f\n", game_ptr->perp_wall_dist);
		game_ptr->line_height = (int)(game_ptr->screen_h / game_ptr->perp_wall_dist);
		game_ptr->draw_start = - game_ptr->line_height / 2 + game_ptr->screen_h  / 2;
		if (game_ptr->draw_start < 0)
			game_ptr->draw_start = 0;
		game_ptr->draw_end = game_ptr->line_height / 2 + game_ptr->screen_h / 2;
		if (game_ptr->draw_end >= game_ptr->screen_h)
			game_ptr->draw_end = game_ptr->screen_h - 1;

	// printf("start: %i\n end: %i\n x: %i\n", game_ptr->draw_start, game_ptr->draw_end, game_ptr->x);
	// usleep(100000);
		for(int y = game_ptr->draw_start; y < game_ptr->draw_end; y++)
		{
			if (game_ptr->side == 0)
			{
				if (worldMap[game_ptr->map_x][game_ptr->map_y] == 1)
					mlx_pixel_put(game_ptr->mlx, game_ptr->win_ptr, game_ptr->x,y , 0x922B21);
				else if (worldMap[game_ptr->map_x][game_ptr->map_y] == 2)
					mlx_pixel_put(game_ptr->mlx, game_ptr->win_ptr, game_ptr->x,y , 0x1F618D);
				else 
						mlx_pixel_put(game_ptr->mlx, game_ptr->win_ptr, game_ptr->x,y , 0xBB8FCE);
			}
			else
				mlx_pixel_put(game_ptr->mlx, game_ptr->win_ptr, game_ptr->x,y , 0x614E16);
		}
	game_ptr->x++;
	}
	return 0;
}