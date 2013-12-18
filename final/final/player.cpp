//
//  player.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "player.h"
#include <iostream>

const int INVENTORY_SIZE = 8;

Player::Player(std::string _name):
	name(_name),
	inventoryBlocks(INVENTORY_SIZE){
		currentLocation = new Room();
	};

Inventory* Player::pGetInventory(){
	return &items;
};


Inventory Player::getInventory(){
	return items;
};

void Player::goTo(Room* r){
	delete currentLocation;
	currentLocation = new Room();
	*currentLocation = *r;
};

Room* Player::pGetCurrentLocation(){
	return currentLocation;
};

Player::Player(const Player& p){
//	std::cout << "in copy constructor" << std::endl;
	name = p.name;
	inventoryBlocks = p.inventoryBlocks;
	items = p.items;
	currentLocation = new Room();
	*currentLocation = *p.currentLocation;
};

Player::~Player(){
	delete currentLocation;
};