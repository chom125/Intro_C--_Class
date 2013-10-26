//write.h

#include <string>
#pragma once


void write(std::ostream& os, int i);
void write(std::ostream& os, float f);
void write(std::ostream& os, std::string);

//helper to empty stringstream
void empty(std::stringstream&);