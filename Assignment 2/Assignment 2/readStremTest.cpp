// Assignment 2-3
// Read a sequence of words from an input stringstream. Use Quit as a word that terminates the input.
// Output the words to another stringstream in the order they were entered. Don't print a word twice.
// Modify the program to sort the words before streaming them to the stringstream. 

#include "TestHarness.h"
#include <iostream>
#include <sstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

std::string readLine(std::string input){	
	std::stringstream sValue(input), final;
	
	std::string word;
	bool firstWord = true;
	while( sValue >> word){
		if(word == "Quit"){
			break;
		}

		if(firstWord){
			final << word;
			firstWord = false;
		}
		else{
			final << " " << word;
		}
	}
	
	return final.str();
}

std::string makeCheckString(std::string input){
	//return the string sans "Quit"
	size_t found = input.find(" Quit");
	return input.substr(0, found);
}

std::string sortString(std::string input){
	std::stringstream sValue(input), final;
	std::vector<std::string> wordList;
	
	//read stream into vector
	std::string word;
	while(sValue >> word){
		if(word == "Quit"){
			//sort vector
			std::sort(wordList.begin(), wordList.end());
			break;
		}
		wordList.push_back(word);
	}

	//enter vector data into stringstream
	bool firstWord = true;
	for(int i = 0; i < wordList.size(); i++){
		if(firstWord){
			final << wordList[i];
			firstWord = false;
		}else{
			final << " " << wordList[i];
		}

	}
	
	return final.str();
}

TEST(inputStreamTest, stringstream){
	std::string s1 = "Peter Paul Mary Quit";
	std::string s1Check = makeCheckString(s1);
	
	std::string s2 = "apples bananas pears Quit";
	std::string s2Check = makeCheckString(s2);
	
	std::string s3 = "11235 87389 277261 denver Broncos Quit";
	std::string s3Check = makeCheckString(s3);
	
	CHECK_EQUAL(readLine(s1), s1Check);
	CHECK_EQUAL(readLine(s2), s2Check);
	CHECK_EQUAL(readLine(s3), s3Check);
}

TEST(inputSTreamSortTest, stringstream){
	std::string s1 = "Peter Paul Mary Quit";
	std::string s1Check = "Mary Paul Peter"; //manually sorted
	std::string s2 = "apples bananas pears Quit";
	std::string s2Check = "apples bananas pears"; //manually sorted
	std::string s3 = "11235 87389 277261 denver Broncos Quit";
	std::string s3Check = "11235 277261 87389 Broncos denver"; //manually sorted
	
	CHECK_EQUAL(sortString(s1), s1Check);
	CHECK_EQUAL(sortString(s2), s2Check);
	CHECK_EQUAL(sortString(s3), s3Check);
}