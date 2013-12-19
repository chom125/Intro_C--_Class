#include "testLevel.h"

Player stevePlayer("Steve");
textGameLoop testLevel(&stevePlayer);

//Game details
std::string entranceText = "You are standing in front of an old, abandoned high school - your old high school."
"Your friends insisted on breaking in and taking a look around, but you stayed behind"
"because breaking and entering isn't exactly on your bucket list and you had some Amazing Spider-Man"
"to get through. As you pull your jacket tight around you, you realize that not only can you see your"
"breath, but your friends have been gone for almost 2 solid hours. Packing up your comics, you stand up"
"and consider your options.";

std::string foyerText = "A foul stench fills the air as you enter McKillian High's central foyer. To your left you see a broken trophy"
"display case. Your class was one of the last in the school's 100 year history. The general disrepair of the"
"building gives you an odd eternal feeling; as if the exploits of you and your peers have been steeped in"
"a space of time several magnitudes more extreme than the intervening years would suggest. While the glass is broken,"
"the trophies, photos and keepsakes are mostly in place. You look down into a broken shard of glass and see something"
"odd in the reflection; odd enough to make you turn around. A wisp of smoke trails down the hallway of lockers emanating"
"from Mr. Schlocter's old classroom.";

std::string mathRoomText = "A young man sits at the front of the classroom, silently engaged with the textbook in front of him. He looks up"
"slowly to meet your gaze \"Make sure your next steps are calculated carefully...\" Next to the"
"sinister student is a glistening mathletes trophy.";

std::string gymnasiumText = "The gymnasium is dark and quiet. You experience a strong agoraphobic chill.";

Room entrance = Room("Entrance", entranceText);
Room foyer = Room("Foyer", foyerText);
Room gymnasium = Room("Gymnasium", gymnasiumText);
Room mathRoom = Room("Math Room", mathRoomText);


//entrance functions
void checkPhone(){
	std::string phonePrompt = "You're a frugal t-mobile user. As such, you find that in a clutch, you have no bars.";
	entrance.setPrompt(phonePrompt);
};

void goToFoyer(){
    testLevel.movePlayer("Foyer");
};

void goToGym(){
	testLevel.movePlayer("Gymnasium");
};

void goToMathRoom(){
	testLevel.movePlayer("Math Room");
};

void readComics(){
	std::string comicPrompt = "The safety of your friends may be up in the air but one thing is certain, Eddy Brock's"
	"transformation into Venom is a compelling storyline if ever there was one";
	
	Room* currentRoom = testLevel.pGetPlayer()->pGetCurrentLocation();
	currentRoom->setPrompt(comicPrompt);
};

void winGame(){
	testLevel.win();
};

//gymnasium functions
void callOutToFriends(){
	gymnasium.setPrompt("You receive only echoes in reply.");
};

//setup helper
void gameInit(){
	//entrance functions
	entrance.addCommand("check phone", checkPhone);
	entrance.addCommand("go to foyer", goToFoyer);
	entrance.addCommand("read comics", readComics);
	
	//foyer actions
	foyer.addCommand("go to math classroom", goToMathRoom);
	foyer.addCommand("go to gym", goToGym);
	
	//math room actions
	mathRoom.addCommand("just win already", winGame);
	
	
	//gymnasium functions
	gymnasium.addCommand("call out to friends", callOutToFriends);
	gymnasium.addCommand("go to foyer", goToFoyer);
	gymnasium.addCommand("read comics", readComics);
	
	testLevel.addRoom(&entrance);
	testLevel.addRoom(&foyer);
	testLevel.addRoom(&mathRoom);
	testLevel.addRoom(&gymnasium);
	
    testLevel.movePlayer("Entrance");
};

