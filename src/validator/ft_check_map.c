/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:18:28 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/06 00:28:51 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_layout(t_data *game)
{
	ft_memset(&game->map, 0, sizeof(t_map));
	ft_memset(&game->p_pos, 0, sizeof(t_player));
	ft_memset(&game->t_pos, 0, sizeof(t_trap));
	ft_memset(&game->img, 0, sizeof(t_image));
	game->moves = 0;
	game->crystal = 0;
	game->dir = 'r';
	game->game_over = 0;
}

static int	ft_read_map_into_matrix(t_data *game, int fd)
{
	int		i;
	char	*line;
	size_t	len;

	i = 0;
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map.map[i] = ft_strdup(line);
		free(line);
		if (!game->map.map[i])
			return (-1);
		i++;
	}
	game->map.map[i] = NULL;
	return (0);
}

int	ft_set_map_layout(t_data *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCannot open map file\n", 2), -1);
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.map)
		return (close(fd), -1);
	if (ft_read_map_into_matrix(game, fd) == -1)
		return (close(fd), ft_free_map(game), -1);
	close(fd);
	return (0);
}

static int	ft_process_map_char(t_data *game, int i, int j)
{
	char	c;

	c = game->map.map[i][j];
	if (c == 'P')
	{
		game->p_pos.x = j;
		game->p_pos.y = i;
		game->map.player++;
	}
	else if (c == 'E')
		game->map.exit++;
	else if (c == 'C')
		game->map.collectible++;
	else if (c == 'T')
		game->map.trap++;
	else if (c != '0' && c != '1')
		return (ft_putstr_fd("Error\nInvalid character in map\n", 2), -1);
	return (0);
}

int	ft_init_positions(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (ft_process_map_char(game, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (ft_check_requirements(game));
}
