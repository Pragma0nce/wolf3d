/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:21:08 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/17 11:21:12 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_input(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	
	return(0);	
}
