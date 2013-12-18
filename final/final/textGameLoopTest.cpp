#include "testHarness.h"
#include "textGameLoop.h"

std::string tglFuncOutput;

void tglFunc(){
	tglFuncOutput += "tglFunc called.";
};

void tglFunc2(){
	tglFuncOutput += "tglFunc2 called.";
};

void tglFunc3(){
	tglFuncOutput += "tglFunc3 called.";
};

TEST(textGameLoopInitTest, textGameLoop){
//	Player myPlayer = Player("steve");
//	textGameLoop tGL = textGameLoop(myPlayer);
//	Room r = Room("test room", "a big spooky dungeon");
//	
//	myPlayer.goTo(&r);
//	
//	CHECK_EQUAL("test room", myPlayer.pGetCurrentLocation()->getName());
//	
//	r.addCommand("func1", tglFunc);
//	r.addCommand("func2", tglFunc2);
//	r.addCommand("func3", tglFunc3);
//	
//	fptr command1pointer;
//	command1pointer = myPlayer.pGetCurrentLocation()->getCommand("func1");
//	
//	(*command1pointer)();
//	CHECK_EQUAL("tglFunc called.", tglFuncOutput);
};

TEST(delayedPrintTest, delayedPrint){
	//delayedPrint::print(std::cout, "Here is some text that should print slowly");
};

TEST(textGameLoopBeginTest, textGameLoop){
//	Player myPlayer = Player("steve");
//	textGameLoop tGL = textGameLoop(myPlayer);
//	Room r = Room("test room", "a big spooky dungeon");
//	
//	myPlayer.goTo(&r);
//	
//	CHECK_EQUAL("test room", myPlayer.pGetCurrentLocation()->getName());
//	
//	r.addCommand("func1", tglFunc);
//	r.addCommand("func2", tglFunc2);
//	r.addCommand("func3", tglFunc3);
//	
//	fptr command1pointer;
//	command1pointer = myPlayer.pGetCurrentLocation()->getCommand("func1");
//	
//	tGL.addRoom(r);
//	
//	tGL.begin();
};

TEST(textGameLoopRoomPromptTest, textGameLoop){
//	Player myPlayer = Player("steve");
//	textGameLoop tGL = textGameLoop(myPlayer);
//	Room r = Room("test room", "a big spooky dungeon");
//	
//	myPlayer.goTo(&r);
//	
//	CHECK_EQUAL("test room", myPlayer.pGetCurrentLocation()->getName());
//	
//	r.addCommand("func1", tglFunc);
//	r.addCommand("func2", tglFunc2);
//	r.addCommand("func3", tglFunc3);
//	
//	fptr command1pointer;
//	command1pointer = myPlayer.pGetCurrentLocation()->getCommand("func1");
//	
//	//tGL.outputRoomPrompt(); //a big spooky dungeon
};