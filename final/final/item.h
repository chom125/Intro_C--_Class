//
//  item.h
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__item__
#define __final__item__

#include <string>

class Item{
public:
	Item(std::string _name, std::string _description);
	const std::string name;
	const std::string description;
};

#endif /* defined(__final__item__) */
