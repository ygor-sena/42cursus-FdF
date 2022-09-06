/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 04:43:53 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 16:45:36 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	rotate_x(int keysym, t_map *map);
static int	rotate_y(int keysym, t_map *map);
static int	rotate_z(int keysym, t_map *map);

int	rotate_projection(int keysym, t_map *map)
{
	if (keysym == KEY_A || keysym == KEY_S)
		rotate_x(keysym, map);
	else if (keysym == KEY_D || keysym == KEY_F)
		rotate_y(keysym, map);
	else
		rotate_z(keysym, map);
	return (0);
}

static int	rotate_x(int keysym, t_map *map)
{
	if (keysym == KEY_A)
		map->roll_x = map->roll_x - 0.1;
	else
		map->roll_x = map->roll_x + 0.1;
	return (0);
}

static int	rotate_y(int keysym, t_map *map)
{
	if (keysym == KEY_D)
		map->pitch_y = map->pitch_y - 0.1;
	else
		map->pitch_y = map->pitch_y + 0.1;
	return (0);
}

static int	rotate_z(int keysym, t_map *map)
{
	if (keysym == KEY_G)
		map->yaw_z = map->yaw_z - 0.1;
	else
		map->yaw_z = map->yaw_z + 0.1;
	return (0);
}
