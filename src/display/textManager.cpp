//
//  textManager.cpp
//  V0.1 - 16/02/2015
//
//  Copyright (c) 2015 Remi&Alex. All rights reserved.

#include "textManager.h"

std::vector<Text> TextManager::texts;

void TextManager::render() {
	std::vector<Text>::iterator it = TextManager::texts.begin();
	while(it != TextManager::texts.end()) {
		it->render();
		++it;
	}
}

void TextManager::addText(const Text& text) {
	TextManager::texts.push_back(text);
}
