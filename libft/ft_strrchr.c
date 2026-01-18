/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:25:55 by aalmoman          #+#    #+#             */
/*   Updated: 2026/01/08 16:02:54 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == '\0')
	{
		return ((char *)(&s[i]));
	}
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	return (NULL);
}
