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

int		ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (0);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free((char *)s1);
	return (result);
}

char	*ft_strnjoin_free(char const *s1, char const *s2, size_t n)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] && j < (int)n)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free((char *)s1);
	return (result);
}
