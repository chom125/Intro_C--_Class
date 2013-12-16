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
#include "point.h"
#include "item.h"


class Room{
public:
	Room(std::string _name, std::string _text, std::string _state="default");
	virtual ~Room();
protected:
	std::string state;
	std::string name;
	std::string text;
};

#endif /* defined(__final__room__) */
