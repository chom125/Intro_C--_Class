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
	void transferItem(Inventory& dest, Item it);
	void addItem(Item it);
	void removeItem(Item it);
	void removeItem(std::string name);
	Item getItem(std::string name);
	bool contains(std::string name);
private:
	std::map<std::string, Item> items;
};

#endif /* defined(__final__inventory__) */
