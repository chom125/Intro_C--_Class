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
#include "item.h"


class Room{
public:
	Room(std::string _name, std::string defaultText, std::string _state="default");
	virtual ~Room();
	std::string getState();
	void setState(std::string s);
	std::string getPrompt();
protected:
	std::string state;
	std::string name;
	std::string prompt;
};

#endif /* defined(__final__room__) */
