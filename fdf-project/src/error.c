/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:46:28 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/04 22:28:02 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(int output)
{
	printf("DEU RUIM?\n");
	if (output == 1)
		printf(INVALID_ARGS);
	else if (output == 2)
		perror(INVALID_FILE);
	else if (output == 3)
		perror(ERROR_MLX);
	else if (output == 4)
		perror(ERROR_WIN);
	exit(EXIT_SUCCESS);
}
