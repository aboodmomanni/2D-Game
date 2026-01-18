/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by student           #+#    #+#             */
/*   Updated: 2026/01/19 02:02:06 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

static char	*accumulate_content(char *content, int fd)
{
	char	*row;
	char	*tmp;

	row = get_next_line(fd);
	if (!row)
	{
		free(content);
		return (NULL);
	}
	while (row)
	{
		tmp = content;
		content = ft_strjoin(tmp, row);
		free(tmp);
		free(row);
		if (!content)
			return (NULL);
		row = get_next_line(fd);
	}
	return (content);
}

char	**board_parse(char *filepath)
{
	int		fd;
	char	**grid;
	char	*content;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	if (!content)
		return (NULL);
	content = accumulate_content(content, fd);
	close(fd);
	if (!content)
		return (NULL);
	grid = ft_split(content, '\n');
	free(content);
	if (!grid)
		return (NULL);
	return (grid);
}
