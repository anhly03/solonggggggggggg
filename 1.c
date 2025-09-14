/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:53:11 by phly              #+#    #+#             */
/*   Updated: 2025/09/14 20:01:03 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.ber", O_RDONLY);
	if (fd == -1)
		return (printf("Error"));
	//call get next line, if result != Null -> print it out
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf(line);
		free(line);
	}
	close (fd);
	return (0);
}

