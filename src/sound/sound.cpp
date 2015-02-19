//
//  unit.cpp
//  V0.1 - 18/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#include "sound.h"

Sound::Sound(const std::string& path, const SoundTypes& t) : gMusic(NULL), type(t) {
	if(t == MUSIC) {
		gMusic = Mix_LoadMUS(path.c_str());
		if(gMusic == NULL) {
			printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
		}
	} else {
		gEffect = Mix_LoadWAV(path.c_str());
		if(gEffect == NULL){
			printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
	}
}

void Sound::play() {
	if(type == MUSIC)
		Mix_PlayMusic(gMusic, -1);
	else
		Mix_PlayChannel(-1, gEffect, 0);
}

Sound::~Sound() {
	if(gMusic != NULL) Mix_FreeMusic(gMusic);
	else Mix_FreeChunk(gEffect);
}
