/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:27:42 by idahhan           #+#    #+#             */
/*   Updated: 2024/10/31 21:21:17 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_check(int n, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		if (n == INT_MIN)
		{
			str[1] = '2';
			n = 147483648;
		}
		else
			n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		nbr;

	len = count_digits(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	nbr = ft_check(n, str);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
// int main() {
//     printf("%s\n", ft_itoa(-2945));
//     printf("%s\n", ft_itoa(0));
//     printf("%s\n", ft_itoa(12345));
//     printf("%s\n", ft_itoa(INT_MIN));
//     printf("%s\n", ft_itoa(INT_MAX));
//     return 0;
// }