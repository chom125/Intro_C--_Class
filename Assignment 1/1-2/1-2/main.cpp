//
//  main.cpp
//  Assignment 1-2
//
//  Created by Steve Minor on 10/10/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int i;
    cout << "Enter an int: ";
    cin >> i;
    
    
    double d;
    cout << "\nEnter a double: ";
    cin >> d;
    
    
    string s;
    cout << "\n enter a string: ";
    cin >> s;
    
    cout << "\n\nThe int entered was: " << i << "\nThe double entered was : " << d
    << "\nThe string entered was: " << s << endl;
    
    
    return 0;
}

