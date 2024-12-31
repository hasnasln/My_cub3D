/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agungor <agungor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:54:12 by haslan            #+#    #+#             */
/*   Updated: 2024/11/20 22:04:48 by agungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define EA 0
# define WE 1
# define SO 2
# define NO 3

# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define END 0
# define _CUB_ERROR -1
# define _NOT_OPEN -2
# define _ARGUMAN_ERROR -3

# define _XPM_SO_ERROR -4
# define _XPM_NO_ERROR -5
# define _XPM_EA_ERROR -6
# define _XPM_WE_ERROR -7
# define _ENCIRCLING_WALLS_ERROR -10
# define _MALLOC_ERROR -11
# define _INVALIED_ELEMENT -12

# define _MLX_INIT_ERROR -15
# define _MLX_WINDOW_ERROR -16
# define _MLX_SO_ERROR -17
# define _MLX_NO_ERROR -18
# define _MLX_WE_ERROR -19
# define _MLX_EA_ERROR -20
# define _MLX_ADDR_ERROR -21
# define _MLX_MAIN_IMG_ERROR -22

typedef struct s_img
{
	void			*img;
	int				width;
	int				height;
	char			*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_map
{
	char			**map;
	char			**map2;
	char			*str;
	int				width;
	int				height;
	char			**no;
	char			**so;
	char			**we;
	char			**ea;
	char			**c;
	char			**f;
	int				floor_color;
	int				ceiling_color;
	t_img			*img_so;
	t_img			*img_no;
	t_img			*img_we;
	t_img			*img_ea;
}					t_map;

typedef struct s_player
{
	float			x;
	float			y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	char			direction;
}					t_player;

typedef struct s_ray
{
	float			camera_x;
	float			ray_dir_x;
	float			ray_dir_y;
	int				map_x;
	int				map_y;
	float			side_dist_x;
	float			side_dist_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	float			wall_x;
	int				code;
	int				draw_start;
	int				draw_end;
	t_img			*img;
	float			tex_x;
	float			tex_y;
	float			step;
	float			tex_pos;
}					t_ray;

typedef struct s_img_data
{
	void			*img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*data;
	unsigned int	color;
	int				x;
	int				y_start;
	int				y_end;
	int				side;
}					t_img_data;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_w;
	t_img_data		*img_data;
}					t_mlx;

typedef struct s_cub3d
{
	t_map			*map;
	t_player		*player;
	int				fd;
	t_mlx			*mlx;
}					t_cub3d;

/*-----------------------CHECK--------------------------------*/
void				arg_check(int argc, char **argv);
void				check_map(t_cub3d *cub3d);

void				set_player(t_cub3d *cub3d);

/*-------------------------ALLOCATİON---------------------------*/
void				allocate_cub3d(t_cub3d ***cub3d);
void				program_exit(int error_code);
t_cub3d				**get_cub3d(void);

/*----------------------------READ---------------------------------*/
void				map_center(t_cub3d *cub3d);
void				read_map_features(t_cub3d *cub3d);
void				read_game_map(t_cub3d *cub3d);
void				clone_map(t_cub3d *cub3d);

/*----------------------------RAY-CASTİNG-------------------------------------*/

void				ray_casting(t_cub3d *cub3d);

void				set_player_direction(t_cub3d *cub3d);
void				my_mlx_vertical_line_put(t_img_data *img);

unsigned int		get_pixel_colour(t_img *img, int x, int y);

void				xpm_to_imgae(t_cub3d *cub3d);

unsigned int		get_pixel_colour(t_img *img, int x, int y);

void				my_mlx_vertical_line_put(t_img_data *img);

t_ray				*init_ray(t_cub3d *cub3d);

int					key_press(int keycode);

int					click_exit(void);

void				find_wall(t_ray *ray, t_cub3d *cub3d);

void				draw(t_cub3d *cub3d, int x, t_ray *ray);

int					check_rgb(char *tmp);
int					check_rgb_value(char **tmp);
#endif