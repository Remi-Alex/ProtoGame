//
//  renderer.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "renderer.h"

Renderer::Renderer() {}

void Renderer::render() {
	std::list<GraphicUnit*>::iterator it = units.begin();
	while(it != units.end()) {
		(*it)->render();
		++it;
	}

	std::list<GraphicSpell*>::iterator itS = spells.begin();
	while(itS != spells.end()) {
		if((*itS)->getRemainingDuration() < 0) {
			spells.erase(itS++);
		} else {
			(*itS)->render();
			++itS;
		}
	}
}

bool Renderer::addUnit(GraphicUnit* u) {
	units.push_front(u);
	return true;
}

bool Renderer::addSpell(GraphicSpell* gs) {
	spells.push_front(gs);
	return true;
}
