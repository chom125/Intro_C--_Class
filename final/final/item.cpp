//
//  item.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "item.h"

Item::Item(std::string _name, std::string _description, int _size, bool _isVisible):
	name(_name), description(_description), size(_size), isVisible(_isVisible){};