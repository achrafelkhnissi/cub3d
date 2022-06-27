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
	game_ptr->dir_x = game_ptr->dir_x * cos(-0.1) - game_ptr->dir_y * sin(-0.1);
	game_ptr->dir_y = olddirx * sin(-0.1) + game_ptr->dir_y * cos(-0.1);
	double oldplanx = game_ptr->plane_x;
	game_ptr->plane_x = game_ptr->plane_x * cos(-0.1) - game_ptr->plane_y * sin(-0.1);
	game_ptr->plane_y = oldplanx * sin(-0.1) + game_ptr->plane_y * cos (-0.1);
}
void	rotate_left(t_program *game_ptr)
{
	double olddirx = game_ptr->dir_x;
	game_ptr->dir_x = game_ptr->dir_x * cos(0.1) - game_ptr->dir_y * sin(0.1);
	game_ptr->dir_y = olddirx * sin(0.1) + game_ptr->dir_y * cos(0.1);
	double oldplanx = game_ptr->plane_x;
	game_ptr->plane_x = game_ptr->plane_x * cos(0.1) - game_ptr->plane_y * sin(0.1);
	game_ptr->plane_y = oldplanx * sin(0.1) + game_ptr->plane_y * cos (0.1);
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

void right(t_program * game_ptr)
{
	game_ptr->pos_y +=  game_ptr->plane_y * 0.5 ;
	game_ptr->pos_x +=  game_ptr->plane_x * 0.5 ;
}

void left(t_program * game_ptr)
{
	game_ptr->pos_y -=  game_ptr->plane_y * 0.5 ;
	game_ptr->pos_x -=  game_ptr->plane_x * 0.5 ;
}

int press(int key, t_program* game_ptr)
{
	if (key == RIGHT_R)
	{
		game_ptr->key = key;
		game_ptr->r_right = 1;
	}
	else if (key == LEFT_R)
	{
		game_ptr->key = key;
		game_ptr->r_left = 1;
	}
	else if (key == UP_M)
	{
		game_ptr->key = key;
		game_ptr->r_up = 1;
	}
	else if (key == DOWN_M)
	{
		game_ptr->key = key;
		game_ptr->r_down = 1;
	}
	else if (key == RIGHT_M)
	{
		game_ptr->key = key;
		game_ptr->m_right = 1;
	}
	else if (key == LEFT_M)
	{
		game_ptr->key = key;
		game_ptr->m_left = 1;
	}
	move(key, game_ptr);
	return 0;
}

int release(int key, t_program* game_ptr)
{
	if (key == RIGHT_R)
	{
		game_ptr->key = -1;
		game_ptr->r_right = 0;
	}
	else if (key == LEFT_R)
	{
		game_ptr->key = -1;
		game_ptr->r_left = 0;
	}
	else if (key == UP_M)
	{
		game_ptr->key = -1;
		game_ptr->r_up = 0;
	}
	else if (key == DOWN_M)
	{
		game_ptr->key = -1;
		game_ptr->r_down = 0;
	}	
	else if (key == LEFT_M)
	{
		game_ptr->key = -1;
		game_ptr->m_left = 0;
	}	
	else if (key == RIGHT_M)
	{
		game_ptr->key = -1;
		game_ptr->m_right = 0;
	}	
	return 0;
}

int move(int key, t_program* game_ptr)
{
	key = 1;
	mlx_destroy_image(game_ptr->mlx, game_ptr->img_ptr);
	game_ptr->img_ptr = mlx_new_image(game_ptr->mlx, game_ptr->screen_w, game_ptr->screen_h);
	if (game_ptr->r_right == 1)
	{
		printf("key:%i\n",key);
	
		rotate_right(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}
	else if (game_ptr->r_left == 1)
	{
				printf("plane x: %f, ", game_ptr->plane_x);
			printf("plane y: %f\n", game_ptr->plane_y);
		rotate_left(game_ptr);
		printf(" first plane x: %f, ", game_ptr->plane_x);
		printf(" first plane y: %f\n", game_ptr->plane_y);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}
	else if (game_ptr->r_up == 1)
	{
		if(worldMap[(int) (game_ptr->pos_x + game_ptr->dir_x )][(int) (game_ptr->pos_y + game_ptr->dir_y)] == 0)
			forword(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}
	else if (game_ptr->r_down == 1)
	{
		if(worldMap[(int) (game_ptr->pos_x - game_ptr->dir_x )][(int) (game_ptr->pos_y - game_ptr->dir_y)] == 0)
		back(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}
	else if (game_ptr->m_right == 1)
	{
		if(worldMap[(int) (game_ptr->pos_x)][(int) (game_ptr->pos_y +  game_ptr->dir_y + game_ptr->plane_y)] == 0)
		right(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}	
	else if (game_ptr->m_left == 1)
	{
		if(worldMap[(int) (game_ptr->pos_x)][(int) (game_ptr->pos_y +  game_ptr->dir_y - game_ptr->plane_y)] == 0)
		left(game_ptr);
		mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		game_ptr->x = 0;
		lunch_game(game_ptr);
	}
	return 0;
}

void texture(t_program *game_ptr)
{
		// int pixel;
	void *tex;
	int width;
	int height;
	int len;
	int bpp;
	int end;
	double wallx;
	// pixel = NULL;
	if (game_ptr->side == 0 && game_ptr->step_x == -1)
		tex = mlx_xpm_file_to_image(game_ptr->mlx, "srcs/DDA/wood.xpm", &width, &height);
	if (game_ptr->side == 0 && game_ptr->step_x == 1)
		tex = mlx_xpm_file_to_image(game_ptr->mlx, "srcs/DDA/w.xpm", &width, &height);
	if (game_ptr->side == 1 && game_ptr->step_y == -1)
		tex = mlx_xpm_file_to_image(game_ptr->mlx, "srcs/DDA/black-1.xpm", &width, &height);
	if (game_ptr->side == 1 && game_ptr->step_y == 1)
		tex = mlx_xpm_file_to_image(game_ptr->mlx, "srcs/DDA/datacenter.xpm", &width, &height);
	int *texarr = (int *)mlx_get_data_addr(tex, &len, &bpp, &end);
	if (game_ptr->side == 0)
		wallx = game_ptr->pos_y + game_ptr->perp_wall_dist * game_ptr->raydir_y;
	else
		wallx = game_ptr->pos_x + game_ptr->perp_wall_dist * game_ptr->raydir_x;
	 wallx -= (int)((wallx));
	 int texx = (int)(wallx * (double)(width));
	 if (game_ptr->side == 0 && game_ptr->raydir_x > 0) texx = width - texx - 1;
	  if (game_ptr->side == 1 && game_ptr->raydir_x < 0) texx = width - texx - 1;
	  double step = 1.0 * height / game_ptr->line_height;
	  double texpos = (game_ptr->draw_start - screenHeight / 2 + game_ptr->line_height / 2) * step;
	  for(int y = game_ptr->draw_start; y < game_ptr->draw_end; y++)
	  {
		  int texy = (int)texpos & (height - 1);
		  texpos += step;
		// game_ptr->img_arr[screenWidth * game_ptr->draw_start + game_ptr->x]
		//   char *pixel = game_ptr->img_arr + (y * game_ptr->img_len + (game_ptr->x * 4));
		 int *pixel = game_ptr->img_arr + (y * (game_ptr->screen_w) + (game_ptr->x ));
		 int color = texarr[height * texy  + texx];
		 if (game_ptr->side == 1)
		 	color = (color >> 1) & 8355711;
		 *pixel = color;
		//   pixel =(y * game_ptr->img_len + (game_ptr->x * 4));
		 
			// *(int *)pixel=  texarr[height * texy  + texx];
		// game_ptr->img_arr[pixel] = color;

		// // game_ptr->img_arr[(pixel + 3)] = color >> 24;
		  
	  }
	for(int y = 0; y < game_ptr->draw_start; y++)
	{
		int *pixel = game_ptr->img_arr + y * game_ptr->screen_w + (game_ptr->x);
		*pixel = 0x1829A4;
	}
		for(int y = game_ptr->draw_end; y < game_ptr->screen_h; y++)
	{
		int *pixel = game_ptr->img_arr + (y * game_ptr->screen_w + (game_ptr->x));
		*pixel = 0xF7EFEE;
	}
// 		  for(int y = game_ptr->draw_start; y < game_ptr->draw_end; y++)
// 		{
// 				pixel = game_ptr->img_arr + (y * game_ptr->img_len + (game_ptr->x * 4));
// 				if (game_ptr->side== 1)
// 					*(int *)pixel = 0xA96192;
// 				else
// 					*(int *)pixel = 0x6A3E5C ;
// 		}
}

void draw(t_program *game_ptr)
{
	int end;


	game_ptr->img_arr = (int *)mlx_get_data_addr(game_ptr->img_ptr, &game_ptr->img_bpp, &game_ptr->img_len, &end);
		while (game_ptr->x < game_ptr->screen_w)
	{
		game_ptr->camera_x = 2 * (game_ptr->x / (double)(game_ptr->screen_w)) - 1;
		game_ptr->raydir_x = game_ptr->dir_x + game_ptr->plane_x * game_ptr->camera_x;
		game_ptr->raydir_y = game_ptr->dir_y + game_ptr->plane_y * game_ptr->camera_x;
		game_ptr->map_x = (int)game_ptr->pos_x;
		game_ptr->map_y = (int)game_ptr->pos_y;

		game_ptr->delta_dist_x = sqrt(1 + pow(game_ptr->raydir_y, 2) / pow(game_ptr->raydir_x, 2));
		game_ptr->delta_dist_y = sqrt(1 + pow(game_ptr->raydir_x, 2) / pow(game_ptr->raydir_y, 2));
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
			game_ptr->perp_wall_dist = (game_ptr->map_x - game_ptr->pos_x + (1 - game_ptr->step_x) / 2) / game_ptr->raydir_x;
		else
		game_ptr->perp_wall_dist = (game_ptr->map_y - game_ptr->pos_y + (1 - game_ptr->step_y) / 2) / game_ptr->raydir_y;
		
		game_ptr->line_height = (int)(game_ptr->screen_h / game_ptr->perp_wall_dist);
		game_ptr->draw_start = - game_ptr->line_height / 2 + game_ptr->screen_h  / 2;
		if (game_ptr->draw_start < 0)
			game_ptr->draw_start = 0;
		game_ptr->draw_end = game_ptr->line_height / 2 + game_ptr->screen_h / 2;
		if (game_ptr->draw_end >= game_ptr->screen_h)
			game_ptr->draw_end = game_ptr->screen_h - 1;


		texture(game_ptr);
		game_ptr->x++;
	}
	mlx_put_image_to_window(game_ptr->mlx, game_ptr->win_ptr, game_ptr->img_ptr, 0, 0);
}
int lunch_game(void *ptr)
{
	t_program *game_ptr;

	game_ptr = ptr;
	mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
		 draw(game_ptr);
	return 0;
}





