//
//  sound.h
//  V0.1 - 18/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.
//

#ifndef sound_h
#define sound_h

#include <string>
#include <SDL2/SDL_mixer.h>

typedef enum SoundTypes {
	MUSIC,
	EFFECT
} SoundTypes;

/**
*  @class Sound
*  
*/
class Sound {
	private :
		// ----- Member(s)
		Mix_Music *gMusic;
		Mix_Chunk *gEffect;
		SoundTypes type;
		// ----- Function(s)

	protected :
		// ----- Member(s)
		// ----- Function(s)
	public :
		// ----- Member(s)
		// ----- Function(s)
		Sound(const std::string&, const SoundTypes& type = MUSIC);
		~Sound();
		void play(void);
};

#endif
