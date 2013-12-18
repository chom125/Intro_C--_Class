#include <iostream>
#include "testHarness.h"
#include "room.h"

std::string testFuncOutput;

void testFunc(){
	testFuncOutput += "testFunc called.";
};

void testFunc2(){
	testFuncOutput += "testFunc2 called.";
};

void testFunc3(){
	testFuncOutput += "testFunc3 called.";
};

typedef void (*fptr)(); //function pointer

TEST(roomCommandTest, room){
	testFuncOutput = "";
	
	Room r = Room("test room", "a big spooky dungeon");
	
	CHECK_EQUAL("a big spooky dungeon", r.getPrompt());
	CHECK_EQUAL("default", r.getState());

//	this isn't necessary. pretty cool
//	fptr tf = testFunc;
//	fptr tf2 = testFunc2;
//	fptr tf3 = testFunc3;
	
	r.addCommand("func1", testFunc);
	r.addCommand("func2", testFunc2);
	r.addCommand("func3", testFunc3);
	
	fptr command = r.getCommand("func1");
	(*command)(); //testFunc called
	CHECK_EQUAL("testFunc called.", testFuncOutput);
	
	command = r.getCommand("func2");
	(*command)(); //testFunc2 called
	CHECK_EQUAL("testFunc called.testFunc2 called.", testFuncOutput);
	
	command = r.getCommand("func3");
	(*command)(); //testFunc3 called
	CHECK_EQUAL("testFunc called.testFunc2 called.testFunc3 called.", testFuncOutput);
	
	command = r.getCommand("badCommand");
	(*command)(); //r.notFound called
	CHECK_EQUAL("testFunc called.testFunc2 called.testFunc3 called.", testFuncOutput);
};