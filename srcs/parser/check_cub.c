/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:36:38 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/26 16:44:35 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extention(char *src, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(src) - ft_strlen(to_find);
	while ((src[j] && to_find[i])
		&& (src[j++] == to_find[i++]))
		;
	if (j == ft_strlen(src))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	check_cub_texture(char **content, int *i)
{
	int	found;

	found = 0;
	while (*i < 4 && content[*i])
	{
		if (ft_strncmp(content[*i], "NO ", 3) == 0
			|| ft_strncmp(content[*i], "SO ", 3) == 0
			|| ft_strncmp(content[*i], "WE ", 3) == 0
			|| ft_strncmp(content[*i], "EA ", 3) == 0)
			found++;
		(*i)++;
	}
	if (found != 4 && *i != found)
		ft_puterror("Texture error!\n");
	if (*i == 0)
		ft_puterror("Empty .cub file!\n");
}

void	check_cub_colors(char **content, int *i)
{
	int	found;
	int	j;
	int	ex;

	found = 0;
	ex = *i;
	j = *i + 2;
	while (*i < j && content[*i])
	{
		if (ft_strncmp(content[*i], "F ", 2) == 0
			|| ft_strncmp(content[*i], "C ", 2) == 0)
			found++;
		(*i)++;
	}
	if (*i - ex != found && found != 2)
		ft_puterror("Colors error\n");
}

void	check_cub_content(char **content)
{
	int	i;

	i = 0;
	check_cub_texture(content, &i);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	check_cub_colors(content, &i);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		ft_puterror("Map doesn't exist!\n");
}
