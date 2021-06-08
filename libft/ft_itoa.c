/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:51:18 by tyou              #+#    #+#             */
/*   Updated: 2021/01/08 00:23:28 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	to_pos(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int			ft_len(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*rt;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	if (!(rt = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	rt[len--] = '\0';
	while (len >= 0)
	{
		rt[len] = '0' + to_pos(n % 10);
		n = to_pos(n / 10);
		len--;
	}
	if (sign == -1)
		rt[0] = '-';
	return (rt);
}
