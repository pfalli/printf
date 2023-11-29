/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:48:20 by pfalli            #+#    #+#             */
/*   Updated: 2023/11/29 11:14:38 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//the function check if the are the chars of "set" in the beginning or end of the 
// string and create a new string without them

//	int	ft_strlen(const char *str)
//	{
//		int	x;
//	
//		x = 0;
//		while (str[x] != '\0')
//		{
//			x++;
//		}
//		return (x);
//	}
//	
static int	findset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	// calculate start
	while (s1[start] && findset(s1[start], set))
		start++;
	// calculate end
	while (end > start && findset(s1[end - 1], set)) // - 1 bc of the ending \0
		end--;

	arr = (char *)malloc(sizeof(s1) * (end - start + 1)); // allocate

	if (!arr)
		return (NULL);

	while (start < end) // copying
		arr[i++] = s1[start++];
	arr[i] = 0;
	return (arr);
}

//	int	main(void)
//	{
//		char *a = "$^&potter$^&";
//		char *set = "$^&";
//		ft_strtrim(a, set);
//	
//		printf("%s\n", a);
//	}