/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohuisu <seohuisu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:42:51 by seohuisu          #+#    #+#             */
/*   Updated: 2021/10/20 15:05:35 by seohuisu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str)
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