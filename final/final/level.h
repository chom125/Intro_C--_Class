//
//  level.h
//  final
//
//  Created by Steve Minor on 12/15/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__level__
#define __final__level__

#include <iostream>
#include <vector>
#include "room.h"

class Level{
public:
	Level();
	std::vector<Room> rooms;
};

#endif /* defined(__final__level__) */
