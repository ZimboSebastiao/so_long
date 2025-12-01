/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:37:35 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/01 05:13:51 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_layout(t_data *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player = 0;
	game->map.collectible = 0;
	game->map.trap = 0;
	game->map.exit = 0;
	game->moves = 0;
	game->crystal = 0;
	game->dir = 'r';
}

int	ft_check_requirements(t_data *game)
{
	if (game->map.player < 1)
	{
		ft_putstr_fd("Error\nNot enough players!\n", 2);
		return (-1);
	}
	if (game->map.exit < 1)
	{
		ft_putstr_fd("Error\nNot enough exits!\n", 2);
		return (-1);
	}
	if (game->map.collectible < 1)
	{
		ft_putstr_fd("Error\nNot enough collectibles!\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_check_extention(const char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	while (file[i] != '.')
		i--;
	if (ft_strncmp(&file[i], ".ber", 5) != 0)
	{
		ft_putstr_fd("Invalid Extention.\n", 2);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nThere's no map with that name.\n", 2);
		return (-1);
	}
	close(fd);
	return (0);
}

int	ft_set_map_layout(t_data *game, char *file)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = ft_calloc(1, 1);
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		tmp = ft_strjoin_gnl(tmp, line);
		i++;
		free(line);
	}
	ft_set_stats(game, tmp);
	if (ft_check_requirements(game) < 0)
	{
		free(tmp);
		return (-1);
	}
	ft_get_map_width(game, tmp);
	ft_write_map(game, tmp);
	free(tmp);
	return (0);
}

int	ft_init_positions(t_data *game, int i, int j)
{
	while (game->map.map[i])
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
			{
				game->p_pos.x = j;
				game->p_pos.y = i;
			}
			else if (ft_strchr("1PTEC0", game->map.map[i][j]) == NULL)
			{
				ft_putstr_fd("Error\nInvalid input on map.\n", 2);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (ft_init_traps(game) < 0)
		return (-1);
	return (0);
}
