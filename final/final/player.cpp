//
//  player.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "player.h"

const int INVENTORY_SIZE = 8;

Player::Player(std::string _name, Room& _currentLocation):
	name(_name),
	currentLocation(_currentLocation),
	inventoryBlocks(INVENTORY_SIZE){};

void Player::pickUp(Item i){
	
}