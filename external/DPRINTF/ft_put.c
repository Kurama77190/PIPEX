/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:02:29 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/16 17:29:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int fd, int *compteur)
{
	write(fd, &c, 1);
	(*compteur)++;
}

void	ft_putstr(char *str, int fd, int *compteur)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)", fd, compteur));
	while (str[i])
	{
		ft_putchar(str[i], fd, compteur);
		i++;
	}
}

void	ft_putnbr(int nb, int fd, int *compteur)
{
	if (nb == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		*compteur += 11;
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-', fd, compteur);
		ft_putnbr(nb *(-1), fd, compteur);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48, fd, compteur);
	else
	{
		ft_putnbr(nb / 10, fd, compteur);
		ft_putnbr(nb % 10, fd, compteur);
	}
}

void	ft_putnbr_unsigned(unsigned int nb, int fd, int *compteur)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, fd, compteur);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48, fd, compteur);
	}
}

void	ft_putnbr_base_X(\
		unsigned long long nbr, int fd, int *compteur, char c)
{
	char base[]= "0123456789ABCDEF";
	if (c == 'p')
	{
		if (nbr != 0)
			ft_putstr("0x", fd, compteur);
		if (nbr == 0)
		{
			ft_putstr("(nil)", fd, compteur);
			return ;
		}
		c++;
	}
	if (c != 'p')
	{
		if (nbr >= 16)
			ft_putnbr_base(nbr / 16, fd, compteur, c);
		ft_putchar(base[nbr % 16], fd, compteur);
	}
}

// 	int position_ds_tableau = c /ft_strlen(base);
// 	char char_a_imprimer = base[position_ds_tableau];
// }
// int main (void)
// {
// 	int i = INT_MAX;
// 	int compteur = 0;
// 	char *str = "";

// 	printf("putnbr de printf : \n");
// 	ft_putnbr_unsigned(i, &compteur);
// 	printf("\n");
// 	printf("resultat compteur : %d\n", compteur);

// 	printf("putstr de printf\n");
// 	ft_putstr(str, &compteur);
// 	printf("\n");
// 	printf("nombre de lettre : %d", compteur);

// }

// int main (void)
// {
// 	int i = 1654654;
// 	char c = 'X';
// 	char *base = "0123456789abcdef";
// 	int compteur = 0;

// 	printf("%X", i);
// 	printf("\n");
// 	ft_putnbr_base(i, base, &compteur, c);
// 	printf("\n");
// 	printf("%d\n", compteur);
// }

// int main (void)
// {
// 	char *str = "salut les noobs";
// 	int	compteur = 0;
// 	ft_putstr(str, &compteur);
// 	printf("\n");
// 	printf("%d", compteur);
// }