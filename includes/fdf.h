/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:12:36 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 23:52:09 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "./events.h"

# define INVALID_ARGS 	"Expected argument is './fdf maps/<file_name>'"
# define INVALID_FILE 	"Check if file exists or if file formatting is correct"
# define INVALID_SIZE	"File's map has invalid dimensions"
# define INVALID_MEMORY "Couldn't allocate enough memory for map values"
# define ERROR_MLX 		"Couldn't inicialize mlx_ptr"
# define ERROR_WIN 		"Couldn't inicialize win_ptr"

# define SINE_30 		0.5
# define COSINE_30 		0.866025

# define LOW_HEX_BASE 	"0123456789abcdef"
# define COMMA 			','
# define SPACE 			' '
# define NEW_LINE 		'\n'
# define BLUE_PIXEL 	"0x033DFC"
# define WHITE_PIXEL 	"0xFFFFFF"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef enum e_view
{
	ISOMETRIC = 0,
	ORTHOGRAFIC = 1
}	t_view;

typedef struct s_file
{
	int	z;
	int	color;
}	t_file;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_rotation
{
	double	cos;
	double	sin;
}	t_rotation;

typedef struct s_map
{
	t_file		**coord;
	t_point		scale;
	t_view		projection;
	t_bool		is_colored;
	int			width_x;
	int			length_y;
	int			scale_factor;
	int			center_x;
	int			center_y;
	int			std_zoom;
	int			std_scale;
	int			transl_x;
	int			transl_y;	
	int			usr_z_axis;
	t_rotation	alpha;
	t_rotation	beta;
	t_rotation	gamma;
	double		roll_x;
	double		pitch_y;
	double		yaw_z;
}	t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}	t_fdf;

typedef struct s_bresenham
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	dx1;
	int	dy1;
	int	px;
	int	py;
	int	xe;
	int	ye;
}	t_bresenham;

void		instance_map(t_map *map);
t_file		**instance_coord(int width, int length);
t_bresenham	instance_values(t_point *p1, t_point *p2);
void		free_coord(t_file **coord, int width_x);
void		free_split(char **split);

int			get_file_dimension(t_map *map, int fd);
void		get_file_content(char *file, t_map *map);
int			get_scale(t_map *map);

int			create_image(t_fdf *data);
void		set_map(t_fdf *data, t_point *point, int i, int j);
void		bresenham(t_img *img, t_point *p1, t_point *p2);
int			gradient(int startcolor, int endcolor, int len, int pos);

int			handle_keypress(int keysym, t_fdf *data);
int			zoom_projection(int keysym, t_map *map);
int			change_projection(int keysym, t_map *map);
int			translate_projection(int keysym, t_map *map);
int			change_altitude(int keysym, t_map *map);
int			rotate_projection(int keysym, t_map *map);
int			quit(t_fdf *data);

int			ft_abs(int nbr);
#endif