/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 04:40:56 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/06 07:46:39 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_sdigit(char *c)
{
	if (*c == '-' || *c == '+')
		c++;
	if (*c == '\0')
		return (1);
	while (*c)
	{
		if (*c != '\0' && (*c < '0' || *c > '9'))
			return (1);
		c++;
	}
	return (0);
}