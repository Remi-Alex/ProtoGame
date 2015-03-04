//
//  spellCommand.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "spellCommand.h"
#include "../display/renderer.h"

SpellCommand::SpellCommand(GraphicSpell* gs) : graphicSpell(gs) {
}

void SpellCommand::execute(void*) {
	Renderer::getInstance().addSpell(graphicSpell);
	graphicSpell = new GraphicSpell(graphicSpell);
}
