//
//  player.h
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__player__
#define __final__player__

#include <string>
#include "inventory.h"
#include "room.h"

class Player{
public:
	Player(std::string _name, Room& _currentLocation);
	void pickUp(Item i);
	void placeItem(Item i);
	void goTo(Room& r);
	void getName();
private:
	std::string name;
	int inventoryBlocks;
	Inventory items;
	Room& currentLocation;
};

#endif /* defined(__final__player__) */
