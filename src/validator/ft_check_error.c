/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:18:44 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/06 00:20:12 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill_recursive(t_flood *f, t_point cur)
{
	if (cur.x < 0 || cur.y < 0
		|| cur.x >= f->size.x || cur.y >= f->size.y)
		return ;
	if (f->map[cur.y][cur.x] == '1' || f->map[cur.y][cur.x] == 'F')
		return ;
	if (f->map[cur.y][cur.x] == 'C')
		(*f->collectibles)--;
	if (f->map[cur.y][cur.x] == 'E')
		*f->exit_found = 1;
	f->map[cur.y][cur.x] = 'F';
	ft_flood_fill_recursive(f, (t_point){cur.x + 1, cur.y});
	ft_flood_fill_recursive(f, (t_point){cur.x - 1, cur.y});
	ft_flood_fill_recursive(f, (t_point){cur.x, cur.y + 1});
	ft_flood_fill_recursive(f, (t_point){cur.x, cur.y - 1});
}

void	flood_fill(t_flood *f, t_point start)
{
	ft_flood_fill_recursive(f, start);
}

static int	ft_validate_path(t_data *game)
{
	char	**map_copy;
	int		collectibles;
	int		exit_found;
	t_point	start;
	t_flood	f;

	collectibles = game->map.collectible;
	exit_found = 0;
	map_copy = duplicate_map(game);
	if (!map_copy)
		return (-1);
	start = (t_point){game->p_pos.x, game->p_pos.y};
	f.map = map_copy;
	f.size = (t_point){game->map.width, game->map.height};
	f.collectibles = &collectibles;
	f.exit_found = &exit_found;
	flood_fill(&f, start);
	ft_free_matrix(map_copy);
	if (collectibles != 0)
		return (-1);
	if (!exit_found)
		return (-1);
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
			if (y == 0 || y == game->map.height - 1
				|| x == 0 || x == game->map.width - 1)
			{
				if (game->map.map[y][x] != '1')
					return (ft_putstr_fd("Error\nMap not surrounded\n", 2), -1);
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
