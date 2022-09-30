/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:38:19 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/30 12:58:26 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/* Function to free array/2d array
 */

void	ft_freearray(void **array, int i)
{
	while (i--)
		free(array[i]);
	free(array);
}
