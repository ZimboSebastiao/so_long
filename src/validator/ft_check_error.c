/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:18:44 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 19:18:46 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, t_point size, t_point cur, int *collectibles, int *exit_found)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y)
		return ;
	if (map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == 'F')
		return ;
	if (map[cur.y][cur.x] == 'C')
		(*collectibles)--;
	if (map[cur.y][cur.x] == 'E')
		*exit_found = 1;
	map[cur.y][cur.x] = 'F';
	flood_fill(map, size, (t_point){cur.x + 1, cur.y}, collectibles, exit_found);
	flood_fill(map, size, (t_point){cur.x - 1, cur.y}, collectibles, exit_found);
	flood_fill(map, size, (t_point){cur.x, cur.y + 1}, collectibles, exit_found);
	flood_fill(map, size, (t_point){cur.x, cur.y - 1}, collectibles, exit_found);
}

static char	**duplicate_map(t_data *game)
{
	char	**dup;
	int		i;

	dup = malloc(sizeof(char *) * (game->map.height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		dup[i] = ft_strdup(game->map.map[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static int	ft_validate_path(t_data *game)
{
	char	**map_copy;
	int		collectibles;
	int		exit_found;
	t_point	size;
	t_point	start;

	collectibles = game->map.collectible;
	exit_found = 0;
	map_copy = duplicate_map(game);
	if (!map_copy)
		return (-1);
	size = (t_point){game->map.width, game->map.height};
	start = (t_point){game->p_pos.x, game->p_pos.y};
	flood_fill(map_copy, size, start, &collectibles, &exit_found);
	ft_free_matrix(map_copy);
	
	if (collectibles != 0)
	{
		ft_putstr_fd("Error\nNo valid path to all collectibles\n", 2);
		return (-1);
	}
	if (!exit_found)
	{
		ft_putstr_fd("Error\nNo valid path to exit\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_validate_map_rectangle(t_data *game)
{
	int	y;
	int	first_width;

	if (game->map.height == 0)
		return (ft_putstr_fd("Error\nEmpty map\n", 2), -1);
	first_width = ft_strlen(game->map.map[0]);
	if (first_width == 0)
		return (ft_putstr_fd("Error\nFirst line is empty\n", 2), -1);
	y = 0;
	while (y < game->map.height)
	{
		if ((int)ft_strlen(game->map.map[y]) != first_width)
			return (ft_putstr_fd("Error\nMap is not rectangular\n", 2), -1);
		y++;
	}
	game->map.width = first_width;
	return (0);
}

int	ft_validate_walls(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (y == 0 || y == game->map.height - 1 || 
				x == 0 || x == game->map.width - 1)
			{
				if (game->map.map[y][x] != '1')
					return (ft_putstr_fd("Error\nMap not surrounded by walls\n", 2), -1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_error(t_data *game, char *file)
{
	ft_init_map_layout(game);
	if (ft_check_extention(file) < 0)
		return (-1);
	if (ft_count_map_rows(game, file) < 0)
		return (-1);
	if (ft_set_map_layout(game, file) < 0)
		return (-1);
	if (ft_validate_map_rectangle(game) < 0)
		return (ft_free_map(game), -1);
	if (ft_validate_walls(game) < 0)
		return (ft_free_map(game), -1);
	if (ft_init_positions(game) < 0)
		return (ft_free_map(game), -1);
	if (ft_validate_path(game) < 0)
	{
		ft_free_map(game);
		return (-1);
	}
	return (0);
}