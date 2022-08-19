/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_studies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:58:48 by yde-goes          #+#    #+#             */
/*   Updated: 2022/08/19 21:16:23 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

t_point	set_point(int x, int y);
void	q0_bresenham(t_point *p1, t_point *p2);

int	main(void)
{
	t_point	p1;
	t_point	p2;

	p1 = set_point(0, 10);
	p2 = set_point(10, 0);
	q0_bresenham(&p1, &p2);
	return (0);
}

t_point	set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	q0_bresenham(t_point *p1, t_point *p2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = p1->x;
	y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	p = (2 * dy) - dx;
	while (x <= p2->x)
	{
		printf("Pixel location is (%d, %d)\n", x, y);
		x++;
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + ((2 * dy) - (2 * dx));
			y++;
		}
	}
}
