/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:34:12 by nargouse          #+#    #+#             */
/*   Updated: 2021/08/26 16:37:58 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_flag_c(va_list va, int *p_char)
{
	char	c;

	c = va_arg(va, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	(*p_char)++;
	return (0);
}
