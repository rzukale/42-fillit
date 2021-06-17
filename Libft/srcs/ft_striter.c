/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:18:19 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/26 15:18:21 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *str, void (*fnc)(char *))
{
	size_t	i;

	i = 0;
	if (str && *fnc)
	{
		while (str[i])
		{
			fnc(&str[i]);
			i++;
		}
	}
}
