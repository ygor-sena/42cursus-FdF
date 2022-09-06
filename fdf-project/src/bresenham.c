/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:04:47 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 19:58:08 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_plot_ref(t_bresenham *b, t_point *start, int xe, int ye);
static void	plot_x(t_img *img, t_bresenham *b, t_point *p1, t_point *p2);
static void	plot_y(t_img *img, t_bresenham *b, t_point *p1, t_point *p2);

void	bresenham(t_img *img, t_point *p1, t_point *p2)
{
	t_bresenham	b;

	b = instance_values(p1, p2);
	if (b.dy1 <= b.dx1)
	{
		if (b.dx >= 0)
			set_plot_ref(&b, p1, p2->x, 0);
		else
			set_plot_ref(&b, p2, p1->x, 0);
		plot_x(img, &b, p1, p2);
	}
	else
	{
		if (b.dy >= 0)
			set_plot_ref(&b, p1, 0, p2->y);
		else
			set_plot_ref(&b, p2, 0, p1->y);
		plot_y(img, &b, p1, p2);
	}
}

static void	set_plot_ref(t_bresenham *b, t_point *start, int xe, int ye)
{
	if (xe != 0)
	{
		b->x0 = start->x;
		b->y0 = start->y;
		b->xe = xe;
	}
	else
	{
		b->x0 = start->x;
		b->y0 = start->y;
		b->ye = ye;
	}
}

static void	plot_x(t_img *img, t_bresenham *b, t_point *p1, t_point *p2)
{
	int	color;
	int	len_x;

	len_x = p2->x + p1->x;
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
		color = gradient(p1->color, p2->color, len_x, b->x0);
		img_pix_put(img, b->x0, b->y0, color);
	}
}

static void	plot_y(t_img *img, t_bresenham *b, t_point *p1, t_point *p2)
{
	int	color;
	int	len_y;

	len_y = p2->y + p1->y;
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
		color = gradient(p1->color, p2->color, len_y, b->y0);
		img_pix_put(img, b->x0, b->y0, color);
	}
}
