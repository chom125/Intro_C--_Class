#include "testHarness.h"
#include "player.h"
#include <iostream>

TEST(basicPlayerTest, player){
	Player myPlayer = Player("steve");
	Room r = Room("test room", "a big spooky dungeon");
	
	myPlayer.goTo(&r);
	
	CHECK_EQUAL("test room", myPlayer.pGetCurrentLocation()->getName());
	CHECK_EQUAL("a big spooky dungeon", myPlayer.pGetCurrentLocation()->getPrompt());
}

std::string prcOutput;

void playerRoomCommand1(){
	prcOutput += "prc1.";
	std::cout << "prc1."; 
};

void playerRoomCommand2(){
	prcOutput += "prc2.";
	std::cout << "prc2."; 
};

void playerRoomCommand3(){
	prcOutput += "prc3.";
	std::cout << "prc3."; 
};


TEST(playerRoomCommandTest, player){
	prcOutput = "";
	
	Player myPlayer = Player("steve");
	Room r = Room("test room", "a big spooky dungeon");
	
	myPlayer.goTo(&r);
	
	CHECK_EQUAL("test room", myPlayer.pGetCurrentLocation()->getName());
	CHECK_EQUAL("a big spooky dungeon", myPlayer.pGetCurrentLocation()->getPrompt());
	
	r.addCommand("func1", playerRoomCommand1);
	r.addCommand("func2", playerRoomCommand2);
	r.addCommand("func3", playerRoomCommand3);
	
	CHECK_EQUAL("func1\nfunc2\nfunc3\n", r.getCommands());
	
	Room* currentLocation = new Room(*myPlayer.pGetCurrentLocation());
	CHECK_EQUAL("func1\nfunc2\nfunc3\n", currentLocation->getCommands());
//	fptr prc1 = currentLocation->getCommand("func1");
//	(*prc1)();
//	prc1 = currentLocation->getCommand("func1");
//	(*prc1)();
//	prc1 = currentLocation->getCommand("func1");
//	(*prc1)();
	
	//CHECK_EQUAL("prc1", prcOutput);

}


TEST(playerCopyConstructor, player){
	//Player myPlayer = Player("steve");
	//playerCopy(myPlayer);
};