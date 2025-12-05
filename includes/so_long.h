#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft1/libft.h"
# include "ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include "get_next_line.h"

# define PIXEL	48
# define ESC	65307

# define UP		0xff52
# define DOWN	0xff54
# define LEFT	0xff51
# define RIGHT	0xff53

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_trap
{
	int	*x;
	int	*y;
}	t_trap;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		collectible;
	int		trap;
	int		exit;
	int		exit_open;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_image
{
	void	*player_0;
	void	*player_1;
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*trap;
	void	*exit;
	void	*exit_open_img;
}	t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	p_pos;
	t_map		map;
	t_image		img;
	t_trap		t_pos;
	int			moves;
	int			crystal;
	char		dir;
	int			game_over;
}	t_data;

// errors
int		ft_validate_map_rectangle(t_data *game);
int		ft_validate_walls(t_data *game);
int		ft_check_error(t_data *game, char *file);
int		ft_check_requirements(t_data *game);
int		ft_check_extention(const char *file);

// layout inicialization
int		ft_init_positions(t_data *game);
int		ft_set_map_layout(t_data *game, char *file);
void	ft_init_map_layout(t_data *game);
int		ft_count_map_rows(t_data *game, char *file);
void	ft_free_map(t_data *game);
void	ft_free_matrix(char **matrix);

// player
void	ft_move_up(t_data *game);
void	ft_move_down(t_data *game);
void	ft_move_right(t_data *game);
void	ft_move_left(t_data *game);
void	ft_move(int key, t_data *game);

// traps
int		ft_init_traps(t_data *game);
int		ft_trap_anim(t_data *game);
int		ft_move_trap_down(t_data *game, int i);
int		ft_move_trap_left(t_data *game, int i);
int		ft_move_trap_right(t_data *game, int i);
int		ft_move_trap_up(t_data *game, int i);
int		ft_move_trap(t_data *game);
void	ft_set_traps(t_data *game);
void	ft_free_traps(t_data *game);

// drawing
int		ft_render(t_data *game);
void	ft_create_player(t_data *game, int pixel);
void	ft_draw_map(t_data *game, int x, int y);
void	ft_open_exit(t_data *game);
void	ft_change_player_c(t_data *game, int pixel, char dir);
void	ft_change_player(t_data *game, int pixel, char dir);
void	ft_create_images(t_data *game);
void	ft_clear_images(t_data *game);
void	ft_destroy_all_images(t_data *game);

// events
int		ft_press_x(t_data *game);
int		ft_key_press(int key, t_data *game);
void	ft_game_over(t_data *game);
void	ft_check_winner(t_data *game);
void	ft_exit_game(t_data *game, int exit_code);

#endif