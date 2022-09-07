/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bresenham.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:04:47 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/01 19:13:04 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
	int color;
}	t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	int		color;
}	t_line;

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

#define LOW_HEX_BASE "0123456789abcdef"

int	get_red(int color)
{
	return (color >> 16);
}

int	get_green(int color)
{
	return (color >> 8 & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	get_rgb(int red, int green, int blue)
{
	return (((red) << 16) + ((green) << 8) + (blue));
}

int	ft_round(double num)
{
	int rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

int	gradient(int startcolor, int endcolor, int len, int pos)
{
	float	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (float)((get_red(endcolor)) - (get_red(startcolor))) / (float)len;
	increment[1] = (float)((get_green(endcolor)) - (get_green(startcolor))) / (float)len;
	increment[2] = (float)((get_blue(endcolor)) - (get_blue(startcolor))) / (float)len;
	new[0] = (get_red(startcolor)) + ft_round(pos * increment[0]);
	new[1] = (get_green(startcolor)) + ft_round(pos * increment[1]);
	new[2] = (get_blue(startcolor)) + ft_round(pos * increment[2]);
	newcolor = get_rgb(new[0], new[1], new[2]);
	return (newcolor);
}

t_bresenham	set_variables(t_line line);
void		set_plot_ref(t_bresenham *b, t_point start, int xe, int ye);
void		plot_x(t_img *img, t_bresenham *b, t_line line);
void		plot_y(t_img *img, t_bresenham *b, t_line line);
void		img_pix_put(t_img *img, int x, int y, int color);

void	bresenham(t_img *img, t_line line)
{
	t_bresenham	b;

	b = set_variables(line);
	if (line.start.color != line.start.color)

	else
		line.color = line.start.color;
	if (b.dy1 <= b.dx1)
	{
		if (b.dx >= 0)
			set_plot_ref(&b, line.start, line.end.x, 0);
		else
			set_plot_ref(&b, line.end, line.start.x, 0);
		plot_x(img, &b, line);
	}
	else
	{
		if (b.dy >= 0)
			set_plot_ref(&b, line.start, 0, line.end.y);
		else
			set_plot_ref(&b, line.end, 0, line.start.y);
		plot_y(img, &b, line);
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

t_bresenham	set_variables(t_line line)
{
	t_bresenham	b;

	b.x0 = 0;
	b.y0 = 0;
	b.dx = line.end.x - line.start.x;
	b.dy = line.end.y - line.start.y;
	b.dx1 = abs(b.dx);
	b.dy1 = abs(b.dy);
	b.px = 2 * b.dy1 - b.dx1;
	b.py = 2 * b.dx1 - b.dy1;
	b.xe = 0;
	b.ye = 0;
	return (b);
}

void	set_plot_ref(t_bresenham *b, t_point start, int xe, int ye)
{
	if (xe != 0)
	{
		b->x0 = start.x;
		b->y0 = start.y;
		b->xe = xe;
	}
	else
	{
		b->x0 = start.x;
		b->y0 = start.y;
		b->ye = ye;
	}
}

void	plot_x(t_img *img, t_bresenham *b, t_line line)
{
	int	i;
	int diff_line;

	i = 0;
	diff_line = max(abs(b->x0), b->xe);
	img_pix_put(img, b->x0, b->y0, line.color);
	while (b->x0 < b->xe)
	{
		b->x0 = b->x0 + 1;
		if (b->px < 0)
			b->px = b->px + 2 * b->dy1;
		else
		{
			if ((b->dx < 0 && b->dy < 0) || (b->dx > 0 && b->dy > 0))
				b->y0 = b->y0 + 1;
			else
				b->y0 = b->y0 - 1;
			b->px = b->px + 2 * (b->dy1 - b->dx1);
		}
		img_pix_put(img, b->x0, b->y0, line.color);
		i++;
	}
}

void	plot_y(t_img *img, t_bresenham *b, t_line line)
{
	int	i;

	i = 0;
	img_pix_put(img, b->x0, b->y0, line.color);
	while (b->y0 < b->ye)
	{
		b->y0 = b->y0 + 1;
		if (b->py <= 0)
			b->py = b->py + 2 * b->dx1;
		else
		{
			if ((b->dx < 0 && b->dy < 0) || (b->dx > 0 && b->dy > 0))
				b->x0 = b->x0 + 1;
			else
				b->x0 = b->x0 - 1;
			b->py = b->py + 2 * (b->dx1 - b->dy1);
		}
		img_pix_put(img, b->x0, b->y0, line.color);
		i++;
	}
}
