/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 06:41:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:49:56 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_SCENE_H
# define MAIN_SCENE_H

# include "../gui.h"

# define MAIN_SCENE_TOP_HEIGHT 50
# define MAIN_SCENE_BOTTOM_HEIGHT 100

# define MAIN_SCENE_MARGIN 20
# define MAIN_SCENE_CORNER_RADIUS 7
# define MAIN_SCENE_EDGE 1

# define MAIN_SCENE_BUTTON_HEIGHT 50
# define MAIN_SCENE_PAUSE_BUTTON_WIDTH 200
# define MAIN_SCENE_FRAME_BUTTON_WIDTH 120

void				pause_button(t_show *show, t_main_scene *main);
void				next_button(t_show *show, t_main_scene *main);
void				prev_button(t_show *show, t_main_scene *main);
void				end_button(t_show *show, t_main_scene *main);
void				begin_button(t_show *show, t_main_scene *main);
void				faster_button(t_show *show, t_main_scene *main);
void				slower_button(t_show *show, t_main_scene *main);

void				display(t_show *show, t_main_scene *main);
void				frames(t_show *show, t_main_scene *main);
void				labels_1(t_show *show, t_main_scene *main);
void				labels_2(t_show *show, t_main_scene *main);

#endif
