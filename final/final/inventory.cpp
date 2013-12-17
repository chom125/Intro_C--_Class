//
//  inventory.cpp
//  final
//
//  Created by Steve Minor on 12/16/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "inventory.h"

Inventory::Inventory(){};

void Inventory::addItem(Item it){
	items.insert(std::pair<std::string, Item>(it.name, it));
};

void Inventory::removeItem(Item it){
	items.erase(it.name);
};

void Inventory::removeItem(std::string name){
	items.erase(name);
};

void Inventory::transferItem(Inventory& dest, Item it){
	dest.addItem(it);
	removeItem(it);
};

void Inventory::transferItem(Inventory& dest, std::string name){
	std::map<std::string, Item>::iterator it = items.find(name);	
	dest.addItem(it->second);
	removeItem(it->first);
};

Item Inventory::getItem(std::string name){
	std::map<std::string, Item>::iterator it = items.find(name);
	return it->second;
};

bool Inventory::contains(std::string name){
	std::map<std::string, Item>::iterator it = items.find(name);
	if(it == items.end()){
		return false;
	}
	return true;
};

bool Inventory::contains(Item item){
	std::map<std::string, Item>::iterator it = items.find(item.name);
	if(it == items.end()){
		return false;
	}
	return true;
};

