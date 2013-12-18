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
	isFinished(false){
		//take a reference to a vector as an argument
		//look for a room named begin
			// if not found, throw exception
		//player.goto(*begin)
	};

Room textGameLoop::getRoom(std::string rName){
	std::map<std::string, Room>::iterator it = rooms.find(rName);
	return it->second;
};

Player* textGameLoop::pGetPlayer(){
	return &player;
};


void textGameLoop::getUserInput(){
	std::cout << "Enter your command: "; 
	getline(std::cin, input);
};

void textGameLoop::outputRoomPrompt(){
	Room* playerLoc = player.pGetCurrentLocation();
	std::string prompt = playerLoc->getPrompt();
//	std::cout << prompt;
//	delayedPrint::print(std::cout, prompt);
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
	delayedPrint::clear(std::cout);
	delayedPrint::print(std::cout, "You've won!");
}

void textGameLoop::begin(){
//	while(!isFinished){
		delayedPrint::clear(std::cout);
		outputRoomPrompt();
//		delayedPrint::print(std::cout, "\n\navailable commands: \n");
//		//outputRoomCommands();
//		delayedPrint::print(std::cout, "\n\n");
//		//getUserInput();
//		//executeRoomCommand();
//	};
};
