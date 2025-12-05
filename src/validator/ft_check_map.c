#include "so_long.h"

void	ft_init_map_layout(t_data *game)
{
	ft_memset(&game->map, 0, sizeof(t_map));
	ft_memset(&game->p_pos, 0, sizeof(t_player));
	game->moves = 0;
	game->crystal = 0;
	game->dir = 'r';
	game->game_over = 0;
}

int	ft_check_requirements(t_data *game)
{
	if (game->map.player != 1)
	{
		if (game->map.player == 0)
			ft_putstr_fd("Error\nMissing player (P)\n", 2);
		else
			ft_putstr_fd("Error\nToo many players (P)\n", 2);
		return (-1);
	}
	if (game->map.exit != 1)
	{
		if (game->map.exit == 0)
			ft_putstr_fd("Error\nMissing exit (E)\n", 2);
		else
			ft_putstr_fd("Error\nToo many exits (E)\n", 2);
		return (-1);
	}
	if (game->map.collectible < 1)
	{
		ft_putstr_fd("Error\nNo collectibles (C)\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_check_extention(const char *file)
{
	int		len;
	char	*ext;

	if (!file || !*file)
		return (ft_putstr_fd("Error\nNo map file provided\n", 2), -1);
	len = ft_strlen(file);
	if (len < 5)
		return (ft_putstr_fd("Error\nInvalid file name\n", 2), -1);
	ext = (char *)file + len - 4;
	if (ft_strncmp(ext, ".ber", 5) != 0)
		return (ft_putstr_fd("Error\nFile must have .ber extension\n", 2), -1);
	return (0);
}

int	ft_set_map_layout(t_data *game, char *file)
{
	int		fd;
	int		i;
	char	*line;
	size_t	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCannot open map file\n", 2), -1);
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.map)
		return (close(fd), -1);
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
			return (close(fd), ft_free_map(game), -1);
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
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
			if (game->map.map[i][j] == 'P')
			{
				game->p_pos.x = j;
				game->p_pos.y = i;
				game->map.player++;
			}
			else if (game->map.map[i][j] == 'E')
				game->map.exit++;
			else if (game->map.map[i][j] == 'C')
				game->map.collectible++;
			else if (game->map.map[i][j] == 'T')
				game->map.trap++;
			else if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1')
				return (ft_putstr_fd("Error\nInvalid character in map\n", 2), -1);
			j++;
		}
		i++;
	}
	return (ft_check_requirements(game));
}