/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:01:10 by hel-haji          #+#    #+#             */
/*   Updated: 2024/05/17 23:59:26 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keysym, t_fractal *fract)
{
	if (keysym == XK_Escape)
		handle_close(fract);
	if (keysym == XK_Up)
		fract->y_shift -= (0.5 * fract->zoom);
	else if (keysym == XK_Down)
		fract->y_shift += (0.5 * fract->zoom);
	else if (keysym == XK_Right)
		fract->x_shift -= (0.5 * fract->zoom);
	else if (keysym == XK_Left)
		fract->x_shift += (0.5 * fract->zoom);
	else if (keysym == XK_backslash)
		fract->iteration += 1;
	else if (keysym == XK_minus)
		fract->iteration -= 1;
	ft_render(fract);
	return (0);
}

int	handle_mouse(int b, int x, int y, t_fractal *fract)
{
	(void)x;
	(void)y;
	if (b == Button5)
	{
		fract->zoom *= 0.60;
	}
	else if (b == Button4)
	{
		fract->zoom *= 2.02;
	}
	ft_render(fract);
	return (0);
}

int	handle_close(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->image.img);
	mlx_destroy_window(fract->mlx, fract->mlx_window);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(1);
}
