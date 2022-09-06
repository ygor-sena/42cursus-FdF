/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:36:29 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 19:59:48 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_red(int color);
static int	get_green(int color);
static int	get_blue(int color);
static int	get_rgb(int red, int green, int blue);

int	gradient(int start, int end, int len, int pos)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)(get_red(end) - get_red(start)) / (double)len;
	increment[1] = (double)(get_green(end) - get_green(start)) / (double)len;
	increment[2] = (double)(get_blue(end) - get_blue(start)) / (double)len;
	new[0] = get_red(start) + round(pos * increment[0]);
	new[1] = get_green(start) + round(pos * increment[1]);
	new[2] = get_blue(start) + round(pos * increment[2]);
	newcolor = get_rgb(new[0], new[1], new[2]);
	return (newcolor);
}

static int	get_red(int color)
{
	return (color >> 16);
}

static int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

static int	get_blue(int color)
{
	return (color & 0xFF);
}

static int	get_rgb(int red, int green, int blue)
{
	return (((red) << 16) + ((green) << 8) + (blue));
}
