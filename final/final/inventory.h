//
//  inventory.h
//  final
//
//  Created by Steve Minor on 12/16/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__inventory__
#define __final__inventory__


#include <map>
#include "item.h"

class Inventory{
public:
	Inventory();
	void transferItem(Inventory& dest, Item it);
	void transferItem(Inventory& dest, std::string name);
	void addItem(Item it);
	void removeItem(Item it);
	void removeItem(std::string name);
	Item getItem(std::string name);
	bool contains(std::string name);
	bool contains(Item item);
private:
	std::map<std::string, Item> items;
};

#endif /* defined(__final__inventory__) */
