/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 21:59:40 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/17 21:59:46 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char							*ft_base(unsigned int n, int b)
{
	char						*ret;
	char						*r;
	int							i;
	int							j;

	ret = ft_memalloc(128);
	r = ft_memalloc(128);
	j = 0;
	i = 0;
	while (n)
	{
		if (n % b < 10)
			ret[i++] = (n % b) + 48;
		else
			ret[i++] = (n % b) + 55;
		n /= b;
	}
	b = 8;
	ft_colendl(ret);
	while (i < b)
		ret[i++] = '0';
	while (i--)
		r[j++] = ret[i];
	return (r);
}

// void						ft_format(char *arv)
// {
// 	char ret[17];
// 	char *av = ft_get(arv);
// 	memset((void*)ret, 0, 17);
// 	int j = 0;
// 	int i = strlen(av) - 1;
// 	while (i >= 0 )
// 	{
// 		ret[j++] +=  '\\';
// 		ret[j++] += 'x';
// 		ret[j++] = av[i - 1];
// 		ret[j++] = av[i];
// 		i -= 2;
// 	}
// 	printf("%s\n", ret);
// }
