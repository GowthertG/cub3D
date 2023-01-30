/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:49:24 by hhaddouc          #+#    #+#             */
/*   Updated: 2023/01/30 18:46:57 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int keycode, void *cb)
{
  t_cub *cub = (t_cub *)cb;


  int x = (cub->player->y + 16);
  int y = (cub->player->x + 16);
  if (keycode == DOWN &&  cub->map[((cub->player->y + 16 + PLAYER_SPEED) / 32)][(cub->player->x + 16) /32] != '1')
    cub->player->y += PLAYER_SPEED;
  else if (keycode == UP && cub->map[((cub->player->y + 16 - PLAYER_SPEED) / 32)][(cub->player->x + 16) /32] != '1')
    cub->player->y -= PLAYER_SPEED;
  else if (keycode == LEFT && cub->map[((cub->player->y + 16) / 32)][(cub->player->x + 16 + PLAYER_SPEED) /32] != '1')
    cub->player->x += PLAYER_SPEED;
  else if (keycode == RIGHT && cub->map[((cub->player->y + 16) / 32)][(cub->player->x + 16 - PLAYER_SPEED) /32] != '1')
    cub->player->x -= PLAYER_SPEED;
  render(cub);
}

int main ()
{
  t_cub *cub;
  
  init_data(&cub);
  render(cub);
  mlx_hook(cub->win, 2, 0L, &key_hook, cub);
  mlx_loop(cub->mlx);
}