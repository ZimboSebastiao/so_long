/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:37:02 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/03 11:30:01 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_map_rectangle(t_data *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		if (ft_strlen(game->map.map[y]) != (size_t)game->map.width)
		{
			ft_putstr_fd("Error\nMap's not rectangle.\n", 2);
			return (-1);
		}
		y++;
	}
	return (0);
}

int	ft_validate_inner_walls(t_data *game, int y)
{
	if (game->map.map[y][0] != '1')
	{
		ft_putstr_fd("Error\nMap's walls are not closed.\n", 2);
		return (-1);
	}
	if (game->map.map[y][game->map.width - 1] != '1')
	{
		ft_putstr_fd("Error\nMap's walls are not closed.\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_validate_border_walls(t_data *game, int y, int x)
{
	while (game->map.map[y][x])
	{
		if (game->map.map[y][x] != '1')
		{
			ft_putstr_fd("Error\nMap's walls are not closed.\n", 2);
			return (-1);
		}
		x++;
	}
	return (0);
}

int	ft_validate_all_walls(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y])
	{
		if (y == 0 || y == (game->map.height - 1))
		{
			if (ft_validate_border_walls(game, y, x) < 0)
				return (-1);
		}
		else
		{
			if (ft_validate_inner_walls(game, y) < 0)
				return (-1);
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_check_error(t_data *game, char *file)
{
	if (ft_check_extention(file) < 0)
		return (-1);
	ft_init_map_layout(game);
	ft_count_map_rows(game, file);
	if (ft_set_map_layout(game, file) < 0)
		return (-1);
	if (ft_validate_map_rectangle(game) < 0 || ft_validate_all_walls(game) < 0)
	{
		ft_free_map(game);
		return (-1);
	}
	if (ft_init_positions(game, 0, 0) < 0)
	{
		ft_free_map(game);
		free(game->t_pos.x);
		free(game->t_pos.y);
		return (-1);
	}
	return (0);
}
