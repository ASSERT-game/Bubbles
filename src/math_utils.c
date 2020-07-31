/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:22:43 by home              #+#    #+#             */
/*   Updated: 2020/07/30 19:25:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	normal_velocity(t_bubble *bubble, int d_x, int d_y, double *dest_x, double *dest_y)
{
	// \left(av_{x}\ +\ bv_{y},\ -bv_{x}\ +\ av_{y}\right)

	double	h;
	double	result;

	h = sqrt(d_x * d_x + d_y * d_y);

	double	a;
	double	b;

	a = d_x / h;
	b = d_y / h;

	// printf("VEL: %f, %f\n", bubble->vel_x, bubble->vel_y);

	result = bubble->vel_x * a + bubble->vel_y * b;

	*dest_x += result * a;
	*dest_y += result * b;
}

void	tangent_velocity(t_bubble *bubble, int d_x, int d_y, double *dest_x, double *dest_y)
{
	double	h;
	double	result;

	h = sqrt(d_x * d_x + d_y * d_y);

	double	a;
	double	b;

	a = d_x / h;
	b = d_y / h;
	result = -1 * bubble->vel_x * b + bubble->vel_y * a;

	// if (result > 0)
	// {
		*dest_x += result * -1 * b;
		*dest_y += result * a;
	// }
}
