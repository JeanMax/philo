/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 04:06:27 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/09 01:44:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks for a blank character; that is, a space or a tab.
*/

#include "libft.h"

int ft_isblank(int i)
{
	if (i == ' ' || i == '\t')
		return (8);
	return (0);
}