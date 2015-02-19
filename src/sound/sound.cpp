//
//  unit.cpp
//  V0.1 - 18/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#include "sound.h"

Sound::Sound(const std::string& path) : gMusic(NULL) {
	gMusic = Mix_LoadMUS(path.c_str());
	if(gMusic == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Sound::play() {
	Mix_PlayMusic(gMusic, -1);
}
