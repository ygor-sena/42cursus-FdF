/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:43:37 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/06 20:52:47 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define MLX_WIDTH 1024
# define MLX_HEIGHT 600
# define MLX_TITLE "FdF - Fil de Fer"
# define KEY_ESC						0xFF1B
# define KEY_MINUS						0x002D  
# define KEY_EQUAL                      0x003D   
# define KEY_LEFT                       0xFF51
# define KEY_UP                         0xFF52
# define KEY_RIGHT                      0xFF53
# define KEY_DOWN                       0xFF54 
# define KEY_A                          0x0061
# define KEY_S                          0x0073
# define KEY_D                          0x0064
# define KEY_F                          0x0066
# define KEY_G                          0x0067
# define KEY_H                          0x0068
# define KEY_I                          0x006F
# define KEY_O                          0x0069
# define KEY_R							0x0072
# define KEY_Z                          0x007A 
# define KEY_X							0x0078
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17

typedef enum e_mlx_event
{
	NOEVENTMASK = 0L,
	KEYPRESSMASK = 1L << 0,
}	t_mlx_event;
#endif