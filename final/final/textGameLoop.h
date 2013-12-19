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
#include <vector>
#include "player.h"
#include "room.h"
#include "delayedPrint.h"

class textGameLoop{
public:
	textGameLoop(Player* _player);
	void begin();
	Player* pGetPlayer();
	Room* getRoom(std::string rName);
	void getUserInput();
	void outputRoomPrompt();
	void outputRoomCommands();
	void executeRoomCommand();
	void addRoom(Room* r);
    void movePlayer(std::string roomName);
	void win();
private:
	std::string input;
	bool isFinished;
	Player* player;
	std::map<std::string, Room*> rooms;
};

#endif /* defined(__final__textGameLoop__) */
