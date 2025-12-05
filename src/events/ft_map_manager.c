/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:20:15 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 19:20:18 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_map_rows(t_data *game, char *file)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCannot open map file\n", 2), -1);
	rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		free(line);
	}
	close(fd);
	if (rows == 0)
		return (ft_putstr_fd("Error\nEmpty map\n", 2), -1);
	game->map.height = rows;
	return (0);
}

void	ft_free_map(t_data *game)
{
	int	i;

	i = 0;
	if (game->map.map)
	{
		while (i < game->map.height)
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
		game->map.map = NULL;
	}
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}