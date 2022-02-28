/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:50:56 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/28 19:59:47 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_line_count(char *file)
{
	int		i;
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	i = 0;
	ret = get_next_line(fd, &line);
	while (ret == 1)
	{
		i++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	close(fd);
	if (i != 0)
		free(line);
	if (ret == -1)
		ft_quit("Error while reading file\n");
	return (i);
}

static char	**malloc_empty_map(char *file)
{
	int		n_lines;
	char	**map;

	n_lines = get_line_count(file);
	map = (char **)malloc(sizeof(char *) * (n_lines + 1));
	if (map == NULL)
		ft_quit("Malloc error\n");
	map[n_lines] = NULL;
	return (map);
}

static char	**fill_map(char *file, char **map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = line;
		i++;
	}
	close(fd);
	return (map);
}

char	**read_map(char *file)
{
	char	**map;
	char	*line;
	int		fd;

	map = malloc_empty_map(file);
	map = fill_map(file, map);
	return (map);
}
