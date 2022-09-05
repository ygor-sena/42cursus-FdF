/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:04:47 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/02 17:11:32 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_plot_ref(t_bresenham *b, t_point start, int xe, int ye);
static void	plot_x(t_img *img, t_bresenham *b, t_stroke line);
static void	plot_y(t_img *img, t_bresenham *b, t_stroke line);

void	bresenham(t_img *img, t_stroke line)
{
	t_bresenham	b;

	b = instance_values(line);
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

static void	set_plot_ref(t_bresenham *b, t_point start, int xe, int ye)
{
	b->ref = start.x;
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

static void	plot_x(t_img *img, t_bresenham *b, t_stroke line)
{
	int	color;

	/* color = gradient(line.start.color, line.end.color, line.gap_x, b->x0);
	img_pix_put(img, b->x0, b->y0, color); */
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
		color = gradient(line.start.color, line.end.color, line.gap_x, b->x0);
		img_pix_put(img, b->x0, b->y0, color);
	}
}

static void	plot_y(t_img *img, t_bresenham *b, t_stroke line)
{
	int	color;

	/* color = gradient(line.start.color, line.end.color, line.gap_y, b->x0);
	img_pix_put(img, b->x0, b->y0, color); */
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
		color = gradient(line.start.color, line.end.color, line.gap_x, b->y0);
		img_pix_put(img, b->x0, b->y0, color);
	}
}
