/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:36:24 by ashea             #+#    #+#             */
/*   Updated: 2021/07/04 04:36:25 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_atoi(const char *str)
{
	long	result;
	char	sign;
	long	i;

	i = 0;
	result = 0;
	sign = '+';
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = str[i++];
	if (str[i] == '+' && sign == '-')
		return (0);
	i += (str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (result < 0)
		return ((sign != '-') * -1);
	if (sign == '-')
		result *= -1;
	return ((int)result);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			i;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	i = 0;
	while (s1_copy[i] == s2_copy[i] && s1_copy[i])
		i++;
	if (s1_copy[i] != s2_copy[i])
		return (s1_copy[i] - s2_copy[i]);
	return (0);
}
