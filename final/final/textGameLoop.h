//
//  textGameLoop.h
//  final
//
//  Created by Steve Minor on 12/15/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__textGameLoop__
#define __final__textGameLoop__

#include <string>
#include "player.h"
#include "room.h"
#include "delayedPrint.h"

class textGameLoop{
public:
	textGameLoop(Player _player);
	void begin();
	Player getPlayer();
	Room getRoom(std::string rName);
	void getUserInput();
	void outputRoomPrompt();
	void outputRoomCommands();
	void executeRoomCommand();
	void addRoom(Room r);
	void win();
private:
	std::string input;
	bool isFinished;
	Player player;
	std::map<std::string, Room> rooms;
};

#endif /* defined(__final__textGameLoop__) */
