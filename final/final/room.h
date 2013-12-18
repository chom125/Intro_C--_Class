//
//  room.h
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__room__
#define __final__room__


#include <string>
#include <map>
#include "inventory.h"

typedef void (*fptr)(); //function pointer

class Room{
public:
	Room();
	Room(std::string _name, std::string defaultText, std::string _state="default");
	Room(const Room& r);
	std::string getState();
	void setState(std::string s);
	static void notFound();
	std::string getPrompt();
	std::string getName();
	void setPrompt(std::string s);
	fptr getCommand(std::string);
	std::string getCommands();
	void addCommand(std::string command, fptr action);
	void removeCommand(std::string s);
	void clearCommands();
	
private:
	std::string state;
	std::string name;
	std::string prompt;
	std::map<std::string, fptr> commands;
	Inventory items;
	
};

#endif /* defined(__final__room__) */
