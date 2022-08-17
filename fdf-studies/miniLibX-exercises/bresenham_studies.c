/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_studies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:58:48 by yde-goes          #+#    #+#             */
/*   Updated: 2022/08/17 15:22:45 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

t_point	set_point(int x, int y);
void	bresenham(t_point *p1, t_point *p2);

int	main(void)
{
	t_point	p1;
	t_point	p2;

	p1 = set_point(1, 1);
	p2 = set_point(8, 1);
	bresenham(&p1, &p2);
	return (0);
}

t_point	set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	bresenham(t_point *p1, t_point *p2)
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

/* void	draw_line = (x1, y1, x2, y2) => {    // Iterators, counters required by algorithm
    let x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;    // Calculate line deltas
    dx = x2 - x1;
    dy = y2 - y1;    // Create a positive copy of deltas (makes iterating easier)
    dx1 = Math.abs(dx);
    dy1 = Math.abs(dy);    // Calculate error intervals for both axis
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;    // The line is X-axis dominant
    if (dy1 <= dx1) {        // Line is drawn left to right
        if (dx >= 0) {
            x = x1; y = y1; xe = x2;
        } else { // Line is drawn right to left (swap ends)
            x = x2; y = y2; xe = x1;
        }        pixel(x, y); // Draw first pixel        // Rasterize the line
        for (i = 0; x < xe; i++) {
            x = x + 1;            // Deal with octants...
            if (px < 0) {
                px = px + 2 * dy1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    y = y + 1;
                } else {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }            // Draw pixel from line span at
            // currently rasterized position
            pixel(x, y);
        }    } else { // The line is Y-axis dominant        // Line is drawn bottom to top
        if (dy >= 0) {
            x = x1; y = y1; ye = y2;
        } else { // Line is drawn top to bottom
            x = x2; y = y2; ye = y1;
        }        pixel(x, y); // Draw first pixel        // Rasterize the line
        for (i = 0; y < ye; i++) {
            y = y + 1;            // Deal with octants...
            if (py <= 0) {
                py = py + 2 * dx1;
            } else {
                if ((dx < 0 && dy<0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }            // Draw pixel from line span at
            // currently rasterized position
            pixel(x, y);
        }
    }
 } */