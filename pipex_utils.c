/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoyan <tnoyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:49:09 by tnoyan            #+#    #+#             */
/*   Updated: 2023/07/31 23:07:03 by tnoyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*substr(const char *str, int start, int length)
{
	int		str_len;
	int		substr_len;
	char	*substr;

	str_len = strlen(str);
	if (start >= str_len || length <= 0)
	{
		return (NULL);
	}
	substr_len = length;
	if (start + length > str_len)
	{
		substr_len = str_len - start;
	}
	substr = malloc(sizeof(char) * (substr_len + 1));
	strncpy(substr, str + start, substr_len);
	substr[substr_len] = '\0';
	return (substr);
}

int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	result = malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j])
			j++;
		result[i++] = substr(s, 0, j);
		s += j;
	}
	result[i] = NULL;
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && --size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[h] != '\0')
	{
		n = 0;
		while (s1[h + n] == s2[n] && (h + n) < len)
		{
			if (s1[h + n] == '\0' && s2[n] == '\0')
				return ((char *)&s1[h]);
			n++;
		}
		if (s2[n] == '\0')
			return ((char *)s1 + h);
		h++;
	}
	return (0);
}
