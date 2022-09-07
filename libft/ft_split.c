/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:45:20 by yde-goes          #+#    #+#             */
/*   Updated: 2022/06/24 18:17:36 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char splitter);
static char		**write_words(char **wd_list, const char *str,
					char splitter, size_t wd_qtd);
static char		**free_alloc(char **wd_list, size_t index);

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	wd_qtd;

	if (!s)
		return (NULL);
	wd_qtd = count_words(s, c);
	splitted = malloc((wd_qtd + 1) * (sizeof(*splitted)));
	if (!splitted)
		return (NULL);
	splitted = write_words(splitted, s, c, wd_qtd);
	return (splitted);
}

static size_t	count_words(const char *str, char splitter)
{
	size_t	is_word;

	is_word = 0;
	while (*str && *str == splitter)
		str++;
	while (*str)
	{
		is_word++;
		while (*str && *str != splitter)
			str++;
		while (*str && *str == splitter)
			str++;
	}
	return (is_word);
}

static char	**write_words(char **wd_list, const char *str,
				char splitter, size_t wd_qtd)
{
	size_t	ref;
	size_t	len;
	size_t	i;

	ref = 0;
	len = 0;
	i = 0;
	while (i < wd_qtd)
	{
		while (str[ref + len] && str[ref + len] != splitter)
			len++;
		if (len > 0)
		{
			wd_list[i] = ft_substr(str, ref, len);
			if (!wd_list)
				return (free_alloc(wd_list, i));
			ref += len;
			len = 0;
			i++;
		}
		else
			ref++;
	}
	wd_list[i] = NULL;
	return (wd_list);
}

static char	**free_alloc(char **wd_list, size_t index)
{
	while (index != 0)
	{
		free(wd_list[index]);
		index--;
	}
	free(wd_list);
	return (NULL);
}
