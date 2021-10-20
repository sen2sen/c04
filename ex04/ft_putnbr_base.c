/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohuisu <seohuisu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:39:36 by seohuisu          #+#    #+#             */
/*   Updated: 2021/10/20 14:40:52 by seohuisu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_error(char *base, int *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		*tmp = 1;
	while (base[i] && *tmp == 0)
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				*tmp = 1;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] < 33 || base[i] > 126)
			*tmp = 1;
		else
			i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		tmp;
	long	num;

	i = 0;
	tmp = 0;
	ft_error(base, &tmp);
	num = nbr;
	if (tmp == 0)
	{
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (base[i])
			i++;
		if (num < i)
			ft_putchar(base[num]);
		if (num >= i)
		{
			ft_putnbr_base(num / i, base);
			ft_putnbr_base(num % i, base);
		}
	}
}

#include <stdio.h>

void	main(void)
{
	int nbr;
	nbr = 100;
	char base[50] = "0123456789ABCDEF";
	ft_putnbr_base(nbr,base);
}
