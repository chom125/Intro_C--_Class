//
//  player.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "player.h"

const int INVENTORY_SIZE = 8;

Player::Player(std::string _name):
	name(_name),
	inventoryBlocks(INVENTORY_SIZE){};

Inventory* Player::pGetInventory(){
	return &items;
};

void Player::goTo(Room* r){
	currentLocation = r;
};

Room* Player::pGetCurrentLocation(){
	return currentLocation;
};