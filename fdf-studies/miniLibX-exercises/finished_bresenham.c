/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finished_bresenham.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:04:47 by yde-goes          #+#    #+#             */
/*   Updated: 2022/08/18 21:17:01 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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

t_bresenham	set_variables(void)
{
	t_bresenham	b;

	b.x0 = 0;
	b.y0 = 0;
	b.dx = 0;
	b.dy = 0;
	b.dx1 = 0;
	b.dy1 = 0;
	b.px = 0;
	b.py = 0;
	b.xe = 0;
	b.ye = 0;
	return (b);
}

void	plot_x(t_bresenham *b);
void	plot_y(t_bresenham *b);

void	set_plot_ref(t_bresenham *b, t_point *start, int xe, int ye)
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

void	bresenham(t_point *start, t_point *end)
{
	t_bresenham	b;

	b = set_variables();
	b.dx = end->x - start->x;
	b.dy = end->y - start->y;
	b.dx1 = abs(b.dx);
	b.dy1 = abs(b.dy);
	b.px = 2 * b.dy1 - b.dx1;
	b.py = 2 * b.dx1 - b.dy1;
	if (b.dy1 <= b.dx1)
	{
		if (b.dx >= 0)
			set_plot_ref(&b, start, end->x, 0);
		else
			set_plot_ref(&b, end, start->x, 0);
		plot_x(&b);
	}
	else
	{
		if (b.dy >= 0)
			set_plot_ref(&b, start, 0, end->y);
		else
			set_plot_ref(&b, end, 0, start->y);
		plot_y(&b);
	}
}

void	plot_x(t_bresenham *b)
{
	int	i;

	i = 0;
	printf("Pixel location is (%d, %d)\n", b->x0, b->y0);
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
		printf("Pixel location is (%d, %d)\n", b->x0, b->y0);
		i++;
	}
}

void	plot_y(t_bresenham *b)
{
	int	i;

	i = 0;
	printf("Pixel location is (%d, %d)\n", b->x0, b->y0);
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
		printf("Pixel location is (%d, %d)\n", b->x0, b->y0);
		i++;
	}
}
