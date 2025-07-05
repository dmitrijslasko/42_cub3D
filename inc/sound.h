/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:37:53 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:37:54 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
# define SOUND_H

# include "SDL.h"
# include "SDL_mixer.h"
# include "cub3d.h"

Mix_Music	*init_audio(void);

# define BACKGROUND_MUSIC_VOLUME    64

#endif
