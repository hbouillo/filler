/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_scene.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:05:09 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/02 03:03:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_SCENE_H
# define END_SCENE_H

# include "../gui.h"

# define END_SCENE_BUTTON_HEIGHT 50
# define END_SCENE_HECKYEAH_BUTTON_WIDTH 200

# define END_SCENE_CORNER_RADIUS 7
# define END_SCENE_EDGE 1

# define END_SCENE_LABEL_PADDING 100
# define END_SCENE_BUTTON_PADDING -100

# define END_SCENE_POPUP_HEIGHT 300
# define END_SCENE_POPUP_WIDTH 500

# define END_SCENE_SCORE_PADDING_Y 0
# define END_SCENE_SCORE_PADDING_X 50

void		end_buttons(t_show *show, t_end_scene *end);
void		end_labels(t_show *show, t_end_scene *end);
void		end_labels_2(t_show *show, t_end_scene *end);

#endif
