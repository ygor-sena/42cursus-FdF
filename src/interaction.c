/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:47:09 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 19:48:40 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	zoom_projection(int keysym, t_map *map)
{	
	if (keysym == KEY_MINUS)
		map->scale_factor = map->scale_factor - 1;
	else
		map->scale_factor = map->scale_factor + 1;
	return (0);
}

int	change_projection(int keysym, t_map *map)
{
	if (keysym == KEY_I)
		map->projection = ORTHOGRAFIC;
	else
		map->projection = ISOMETRIC;
	return (0);
}

int	translate_projection(int keysym, t_map *map)
{
	if (keysym == KEY_UP)
		map->transl_y = map->transl_y - 5;
	else if (keysym == KEY_DOWN)
		map->transl_y = map->transl_y + 5;
	else if (keysym == KEY_RIGHT)
		map->transl_x = map->transl_x + 5;
	else
		map->transl_x = map->transl_x - 5;
	return (0);
}

int	change_altitude(int keysym, t_map *map)
{
	if (keysym == KEY_Z)
	{
		map->usr_z_axis = map->usr_z_axis + 1;
	}
	else
		map->usr_z_axis = map->usr_z_axis - 1;
	return (0);
}
