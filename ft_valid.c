/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:16:51 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/12 12:12:28 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_valid_fig(void)
{
	char	**arr;

	arr = (char**)malloc(sizeof(char*) * 20);
	arr[0] = ft_strdup("##\n..##");
	arr[1] = ft_strdup("##.\n.##");
	arr[2] = ft_strdup("##..\n##");
	arr[3] = ft_strdup("#...\n###");
	arr[4] = ft_strdup("#..\n.###");
	arr[5] = ft_strdup("##..\n#...\n#");
	arr[6] = ft_strdup("##.\n.#..\n.#");
	arr[7] = ft_strdup("##\n..#.\n..#");
	arr[8] = ft_strdup("###.\n#");
	arr[9] = ft_strdup("###\n.#");
	arr[10] = ft_strdup("##..\n.#..\n.#");
	arr[11] = ft_strdup("##.\n..#.\n..#");
	arr[12] = ft_strdup("##\n...#\n...#");
	arr[13] = ft_strdup("#..\n###");
	arr[14] = ft_strdup("#.\n.###");
	arr[15] = ft_strdup("#...\n##..\n#");
	arr[16] = ft_strdup("#..\n.##.\n.#");
	arr[17] = ft_strdup("#.\n..##\n..#");
	arr[18] = ft_strdup("##\n.##");
	arr[19] = ft_strdup("##.\n##");
	return (arr);
}

char	**ft_valid_fig2(void)
{
	char	**arr;

	arr = (char**)malloc(sizeof(char*) * 13);
	arr[0] = ft_strdup("#...\n##..\n.#");
	arr[1] = ft_strdup("#..\n.##.\n..#");
	arr[2] = ft_strdup("#.\n..##\n...#");
	arr[3] = ft_strdup("##..\n.##");
	arr[4] = ft_strdup("##.\n..##");
	arr[5] = ft_strdup("#..\n##..\n#");
	arr[6] = ft_strdup("#.\n.##.\n.#");
	arr[7] = ft_strdup("#\n..##\n..#");
	arr[8] = ft_strdup("#\n...#\n...#\n...#");
	arr[9] = ft_strdup("#.\n..#.\n..#.\n..#");
	arr[10] = ft_strdup("#..\n.#..\n.#..\n.#");
	arr[11] = ft_strdup("#...\n#...\n#...\n#");
	arr[12] = ft_strdup("####");
	return (arr);
}

int		ft_check_fig(char *str)
{
	char	**samples;
	int		i;

	i = 0;
	samples = ft_valid_fig();
	while (i < 20)
	{
		if (ft_strcmp(str, samples[i]) == 0)
			return (1);
		if (ft_strcmp(str, ft_strrev(samples[i])) == 0)
			return (1);
		i++;
	}
	free(samples);
	samples = ft_valid_fig2();
	while ((i - 20) < 13)
	{
		if (ft_strcmp(str, samples[i - 20]) == 0)
			return (1);
		if (ft_strcmp(str, ft_strrev(samples[i - 20])) == 0)
			return (1);
		i++;
	}
	free(samples);
	return (0);
}

int		ft_validate(int fd)
{
	char	arr[548];
	char	*str;
	int		start;
	int		numb;

	start = read(fd, arr, 548);
	arr[start] = '\0';
	start = 0;
	if (!(ft_check(arr)))
		return (0);
	numb = (ft_strlen(arr) + 1) / 21;
	while (numb-- > 0)
	{
		str = ft_strtrim(ft_strsub(arr, start, 20));
		if (!(ft_check_fig(str)))
			return (0);
		start += 21;
		free(str);
	}
	return (1);
}
