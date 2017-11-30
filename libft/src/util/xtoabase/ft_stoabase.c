/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:40:48 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/29 15:16:00 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	shortlen(short nbr, int base_n)
{
	size_t		len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= (short)base_n;
		len++;
	}
	return (len);
}

char			*ft_stoabase(short nbr, const char *base)
{
	char		*str;
	size_t		len;
	int			sign;
	int			base_n;

	base_n = (int)ft_strlen(base);
	sign = nbr < 0 ? 1 : 0;
	len = shortlen(nbr, base_n) + sign;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n) * (sign ? -1 : 1)];
			nbr /= (short)base_n;
		}
		if (sign)
			str[--len] = '-';
	}
	return (str);
}

void			ft_stoabase_buf(short nbr, const char *base, char *str)
{
	size_t		len;
	int			sign;
	int			base_n;

	base_n = (int)ft_strlen(base);
	sign = nbr < 0 ? 1 : 0;
	len = shortlen(nbr, base_n) + sign;
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n) * (sign ? -1 : 1)];
			nbr /= (short)base_n;
		}
		if (sign)
			str[--len] = '-';
	}
}
