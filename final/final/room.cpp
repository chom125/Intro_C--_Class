//
//  room.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "room.h"

Room::Room(std::string _name, std::string defaultText, std::string _state):
name(_name), prompt(defaultText), state(_state){};

std::string Room::getState(){
	return state;
};

void Room::setState(std::string s){
	state = s;
};

std::string Room::getPrompt(){
	return prompt;
};