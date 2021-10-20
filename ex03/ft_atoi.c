/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohuisu <seohuisu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:12:08 by seohuisu          #+#    #+#             */
/*   Updated: 2021/10/20 13:29:03 by seohuisu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	mul;
	int	num;

	mul = 1;
	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mul *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num *= mul;
	return (num);
}

#include <stdio.h>
 void	main(void)
 {
	 char str[30] = " ---+--+1234ab567";
	 printf("%d", ft_atoi(str));
 }