/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:56:14 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/09 22:25:38 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_line_points(char *str);
static void	get_coordinates(char *point, t_map *map, int x, int y);

int	get_file_dimension(t_map *map, int fd)
{
	int		row_size;
	char	*line;

	line = get_next_line(fd);
	row_size = get_line_points(line);
	map->length_y = 1;
	free(line);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->width_x = get_line_points(line);
		if (row_size != map->width_x)
			return (free(line), 0);
		free(line);
		map->length_y += 1;
	}
	return (1);
}

void	get_file_content(char *file, t_map *map)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	y = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, SPACE);
		x = 0;
		while (x < map->width_x)
		{
			get_coordinates(split[x], map, x, y);
			x++;
		}
		free_split(split);
		free(line);
		y++;
	}
	close(fd);
}

static int	get_line_points(char *str)
{
	int		point;
	t_bool	is_point;

	point = 0;
	is_point = FALSE;
	while (*str != NEW_LINE && *str)
	{
		if (*str != SPACE && is_point == FALSE)
		{
			is_point = TRUE;
			point++;
		}
		else if (*str == SPACE)
			is_point = FALSE;
		str++;
	}
	return (point);
}

static void	get_coordinates(char *point, t_map *map, int x, int y)
{
	char	**pt_content;

	if (ft_strchr(point, COMMA))
	{
		pt_content = ft_split(point, COMMA);
		map->coord[x][y].z = ft_atoi(pt_content[0]);
		map->coord[x][y].color = ft_atoi_base(pt_content[1], LOW_HEX_BASE);
		map->is_colored = TRUE;
		free_split(pt_content);
	}
	else
	{
		map->coord[x][y].z = ft_atoi(point);
		if (map->coord[x][y].z != 0 && map->is_colored == FALSE)
			map->coord[x][y].color = ft_atoi_base(BLUE_PIXEL, LOW_HEX_BASE);
		else
			map->coord[x][y].color = ft_atoi_base(WHITE_PIXEL, LOW_HEX_BASE);
	}
}
