/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:25:57 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/28 18:05:31 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isupper(int c);
static	int	ft_islower(int c);

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1024);
	return (0);
}

static	int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (256);
	return (0);
}

static	int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (512);
	return (0);
}
