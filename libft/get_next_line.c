/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:06:35 by nargouse          #+#    #+#             */
/*   Updated: 2021/11/03 17:29:24 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char	*left = NULL;
	char		buf[BUFSIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFSIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	*line = ft_strndup(left ? left : "", ft_strichr(left ? left : "", '\n'));
	if (ft_strchr(left ? left : "", '\n') != NULL)
		return (ft_if(&left, &tmp));
	while (((ret = read(fd, &buf, BUFSIZE)) > 0) && ft_strchr(buf, '\n') == 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin_free(*line, buf);
	}
	buf[ret] = '\0';
	*line = ft_strnjoin_free(*line, buf, ft_strichr(buf, '\n'));
	if (ret != BUFSIZE && ft_strchr(buf, '\n') == NULL)
		return (ft_free((void **)&left));
	tmp = left;
	left = ft_strdup(ft_strchr(buf, '\n') + 1);
	free(tmp);
	return (1);
}

int		ft_if(char **left, char **tmp)
{
	*tmp = *left;
	*left = ft_strdup(ft_strchr(*left ? *left : "", '\n') + 1);
	free(*tmp);
	return (1);
}
