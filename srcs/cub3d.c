/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:39:12 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/27 18:01:21 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,14,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void	ft_free(t_program *game, char *msg)
{
	int	i;

	i = 0;
	// while (game->map.map[i])
	// 	free(game->map.map[i++]);
	// free(game->map.map);
	mlx_destroy_window(game->mlx, game->win_ptr);
	printf("%s\n", msg);
	// if (ft_strcmp(msg, "BRAVO!") == 0)
	// 	printf("\n%s%s%s\n", GREEN,
	// 		"⊱ ──────────────── {.⋅ ✯ BRAVO! ✯ ⋅.} ───────────────── ⊰", END);
	// else
	// 	printf("\n%s%s%s\n", RED, msg, END);
	exit(EXIT_SUCCESS);
}


int	ft_close(t_program *game)
{
	ft_free(game, "WINDOW CLOSED");
	return (0);
}

void	ft_new_window(t_program *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->screen_w, game->screen_h, "cub3D");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
}

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}



int	main(int ac, char **av)
{
	t_program game_ptr;

	if (ac != 2)
		ft_puterror("Usage: ./cub3D ./path_to_map\n");
	init_game(&game_ptr);
	game_ptr.map.filename = ft_strdup(av[1]); // TODO: free
	parse_map(&game_ptr);
	start_game(&game_ptr);
	mlx_hook (game_ptr.win_ptr, 2, 0, &press, &game_ptr);
	mlx_hook (game_ptr.win_ptr, 3, 0, &release, &game_ptr);
	mlx_loop_hook(game_ptr.mlx, lunch_game, &game_ptr);
	mlx_loop(game_ptr.mlx);
	return (0);
}
