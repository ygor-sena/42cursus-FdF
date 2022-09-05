/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:12:36 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/05 16:26:55 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TO DO: ORGANIZE LIBS AFTER FINISHING THE PROJECT
//TO DO: CHECK WHICH FUNCS ARE STATIC OR NOT
#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include <errno.h>
# include <stdint.h>
# include <math.h>

# include "../libft/libft.h"

# include <mlx.h>
/* This is to get the values (key code) of all 
		the available symbols (key symbols) */

/* This lib is for the Key Tags of mlx_hook! */
# include <X11/X.h>

# define XK_Escape                        0xff1b
//Zoom
# define XK_minus                         0x002d  
# define XK_equal                         0x003d  
//Z Sum
# define XK_KP_Space                      0xff80  
# define XK_z                             0x007a  
//Rotations and translations
# define XK_KP_Left                       0xff96
# define XK_KP_Up                         0xff97
# define XK_KP_Right                      0xff98
# define XK_KP_Down                       0xff99
# define XK_w                             0x0077  
# define XK_a                             0x0061
# define XK_s                             0x0073
# define XK_d                             0x0064
//Z Axis
# define XK_q                             0x0071
# define XK_e                             0x0065


# define ZOOM_IN
# define ZOOM_OUT
# define INVALID_ARGS "Expected argument is './fdf maps/<file_name>'"
# define INVALID_FILE "Invalid file: %s. Check if file exists"
# define ERROR_MLX "Couldn't inicialize mlx_ptr"
# define ERROR_WIN "Couldn't inicialize win_ptr"

# define MLX_WIDTH 1024
# define MLX_HEIGHT 600
# define MLX_TITLE "M3T4V3RS0"

# define MLX_ERROR 1

# define SINE_30 0.866025
# define COSINE_30 0.5

# define LOW_HEX_BASE "0123456789abcdef"
# define COMMA ','
# define SPACE ' '
# define NEW_LINE '\n'

# define BLUE_PIXEL "0x033DFC"
# define GREEN_PIXEL "0xFF00"
# define WHITE_PIXEL "0xFFFFFF"
# define RED_PIXEL "0xFF0000"

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
	int z;
	int color;
}	t_file;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

/* typedef struct s_rotation
{
	int Axx;
	int Axy;
	int Axz;
}	t_rotation; */

typedef struct s_map
{
	t_file	**coord;
	t_point	scale;
	t_bool	is_colored;
	t_view	projection;
	int		width_x;
	int		length_y;
	int		scale_factor;
	//Standard values of map
	int		center_x;
	int		center_y;
	int		view;
	int		std_zoom;
	int		std_scale;
	int		transl_x;
	int		transl_y;
	/* int		roll_x;
	int		pitch_y;
	int		yaw_z; */
	//User variables
	int		usr_z_axis;
	//t_rotation	rotation;
}	t_map;


typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}	t_fdf;

typedef struct s_stroke
{
	t_point	start;
	t_point	end;
	int		gap_x;
	int		gap_y;
	int		color;
}	t_stroke;

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
	int ref;
}	t_bresenham;

int			gradient(int startcolor, int endcolor, int len, int pos);

int			quit(t_fdf *data);

void		instance_map(t_map *map);
t_file		**instance_coord(int width, int length);
t_bresenham	instance_values(t_stroke line);

void		free_coord(t_file **coord, int width_x);
void		free_split(char **split);

int			get_length(char *file);
int			get_width(char *file);

void		fill_axes(char *file, t_map *map);
void		fit_map(t_map *map);
int			set_projection(t_map *map);
int 		get_scale(t_map *map);

void		bresenham(t_img *img, t_stroke line);

void		render_line(t_img *img, t_point start, t_point end, t_map *map);
int			handle_keypress(int keysym, t_fdf *data);
void		img_pix_put(t_img *img, int x, int y, int color);

//void		set_map(char *file_name, t_map *map);

int			create_image(t_fdf *data);
void		set_isometric(t_point *point);
void		set_stroke(t_point start, t_point end, t_stroke *line);
void		error(int output);

int			ft_abs(int nbr);
int			ft_max(int a, int b);
/* THIS WILL BE DELETED */
void		print_coord(t_map *map);
#endif