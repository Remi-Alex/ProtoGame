//
//  spellCommand.cpp
//  V0.1 - 03/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "spellCommand.h"
#include "../display/renderer.h"

SpellCommand::SpellCommand(GraphicSpell* gs, GraphicUnit* p) : graphicSpell(gs), player(p) {
}

void SpellCommand::execute(void*) {
	graphicSpell->setCoordinates(player->getX() + player->getWidth() / 2, player->getY() + player->getHeight() / 2, player->getLastDirection());
	Renderer::getInstance().addSpell(graphicSpell);
	graphicSpell = new GraphicSpell(graphicSpell);
}
