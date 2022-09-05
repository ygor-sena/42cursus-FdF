/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:56:14 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/03 01:41:11 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_line_points(char *str);
static void	get_coordinates(char *point, t_map *map, int x, int y);
//CHECK: get_coordinates will be static?

int	get_width(char *file)
{
	int		fd;
	int		length;
	int		row_size;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0); //ERROR: FILE COUNDN'T BE OPENED
	line = get_next_line(fd);
	row_size = get_line_points(line);
	free(line);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		length = get_line_points(line);
		if (row_size != length)
			return (free(line), -1); //ERROR: INVALID MAP FORMATTING
		free(line);
	}
	close(fd);
	return (length);
}

int	get_length(char *file)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0); //ERROR: FILE COUNDN'T BE OPENED
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		row++;
	}
	close(fd);
	return (row);
}

void	fill_axes(char *file, t_map *map)
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
		//Set a standard color for z? INTERESTING!
		map->coord[x][y].color = -1;
	}
}
