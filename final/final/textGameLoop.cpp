//
//  textGameLoop.cpp
//  final
//
//  Created by Steve Minor on 12/15/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//


#include "textGameLoop.h"

textGameLoop::textGameLoop(Player _player):
	player(_player),
	isFinished(false){};

Room textGameLoop::getRoom(std::string rName){
	std::map<std::string, Room>::iterator it = rooms.find(rName);
	return it->second;
};


void textGameLoop::getUserInput(){
	std::cout << "Enter your command: "; 
	getline(std::cin, input);
};

void textGameLoop::outputRoomPrompt(){
	delayedPrint::print(std::cout, player.pGetCurrentLocation()->getPrompt());
};

void textGameLoop::outputRoomCommands(){
	delayedPrint::print(std::cout, player.pGetCurrentLocation()->getCommands());
};

void textGameLoop::executeRoomCommand(){
	fptr command = player.pGetCurrentLocation()->getCommand(input);
	(*command)();
}

void textGameLoop::addRoom(Room r){
	rooms.insert(std::pair<std::string, Room>(r.getName(), r));
};

void textGameLoop::win(){
	isFinished = true;
}

void textGameLoop::begin(){
	while(!isFinished){
		delayedPrint::clear(std::cout);
		outputRoomPrompt();
		delayedPrint::print(std::cout, "\n\navailable commands: \n");
		outputRoomCommands();
		delayedPrint::print(std::cout, "\n\n");
		getUserInput();
		executeRoomCommand();
	};
};
