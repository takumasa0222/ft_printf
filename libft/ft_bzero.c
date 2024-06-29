/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:09:59 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/22 06:02:07 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*cpy_ptr;

	i = 0;
	cpy_ptr = (unsigned char *)ptr;
	if (!ptr)
		return ;
	while (i < num)
	{
		*cpy_ptr = '\0';
		i++;
		cpy_ptr++;
	}
}
