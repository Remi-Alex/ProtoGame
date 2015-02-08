//
//  renderer.cpp
//  V0.1 - 08/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "renderer.h"

Renderer::Renderer(Window* w) : window(w) {}

void Renderer::render() {
	std::list<GraphicUnit*>::iterator it = units.begin();
	while(it != units.end()) {
		(*it)->render(window);
		++it;
	}
}
