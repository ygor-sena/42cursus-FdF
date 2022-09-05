/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:36:29 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/02 16:57:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_red(int color);
static int	get_green(int color);
static int	get_blue(int color);
static int	get_rgb(int red, int green, int blue);

int	gradient(int startcolor, int endcolor, int len, int pos)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)(get_red(endcolor) - get_red(startcolor)) / (double)len;
	increment[1] = (double)(get_green(endcolor) - get_green(startcolor)) / (double)len;
	increment[2] = (double)(get_blue(endcolor) - get_blue(startcolor)) / (double)len;
	new[0] = get_red(startcolor) + round(pos * increment[0]);
	new[1] = get_green(startcolor) + round(pos * increment[1]);
	new[2] = get_blue(startcolor) + round(pos * increment[2]);
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
/* int	main(void)
{
	char	*hex;
	int		decimal;
	int		red;
	int		green;
	int		blue;

	hex = "0xFFFFFF";
	decimal = ft_atoi_base(hex, LOW_HEX_BASE);
	red = get_red(decimal);
	green = get_green(decimal);
	blue = get_blue(decimal);
	printf("Hex/Decimal: %s | %d\n", hex, decimal);
	printf("RED:   %d\nGREEN: %d\nBLUE:  %d\n", \
			red, green, blue);
	printf("White is: %d\n", get_rgb(red, green, blue));
	return (0);
} */
