// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   init_audio.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/02 00:09:36 by fvargas           #+#    #+#             */
// /*   Updated: 2025/07/02 00:09:37 by fvargas          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "sound.h"
// #include "colors.h"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>

// void	free_audio(void *ptr)
// {
// 	Mix_Music	*music;

// 	music = (Mix_Music *)ptr;
// 	if (music != NULL)
// 	{
// 		Mix_FreeMusic(music);
// 		music = NULL;
// 	}
// 	Mix_CloseAudio();
// }

// Mix_Music	*init_audio(void)
// {
// 	Mix_Music	*background_music;

// 	print_separator_default();
// 	printf(TXT_YELLOW ">>> LOADING BACKGROUND MUSIC\n" TXT_RESET);
// 	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
// 	Mix_VolumeMusic(BACKGROUND_MUSIC_VOLUME);
// 	background_music = Mix_LoadMUS("./assets/sounds/music.wav");
// 	Mix_PlayMusic(background_music, -1);
// 	printf(TXT_GREEN "Done!\n" TXT_RESET);
// 	return (background_music);
// }
