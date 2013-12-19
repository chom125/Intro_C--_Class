//
//  room.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "room.h"
#include <iostream>
void Room::notFound(){
	//if the command is not found, do nothing
    //std::cout << "not found called" << std::endl;
};
Room::Room(){};
Room::Room(std::string _name, std::string defaultText, std::string _state):
name(_name), prompt(defaultText), state(_state){

};

Room::Room(const Room& r){
	state = r.state;
	name = r.name;
	prompt = r.prompt;
	commands = r.commands; //suspect
	items = r.items;
    
    std::cout << "Room copy constructor called" << std::endl;
};

std::string Room::getState(){
	return state;
};

void Room::setState(std::string s){
	state = s;
};

void Room::setPrompt(std::string s){
	prompt = s;
};


std::string Room::getPrompt(){
	return prompt;
};

std::string Room::getName(){
	return name;
};

fptr Room::getCommand(std::string s){
//	std::cout << "looking for: " << s << ". " << std::endl;
	std::map<std::string, fptr>::iterator it = commands.find(s);
	if(it != commands.end()){
//		std::cout << "found" << std::endl;
		return it->second;
	}
//	std::cout << "not found" << std::endl;
	return notFound;
};


std::string Room::getCommands(){
	std::string commandList;
	
	for(std::map<std::string, fptr>::iterator it = commands.begin(); it != commands.end(); ++it){
		commandList += it ->first + "\n";
	}
	
	return commandList;
};

void Room::addCommand(std::string command, fptr action){
	commands.insert(std::pair<std::string, fptr>(command, action));
};

void Room::removeCommand(std::string s){
	std::map<std::string, void(*)()>::iterator it = commands.find(s);
	commands.erase(it);
};

void Room::clearCommands(){
	commands.clear();
};


