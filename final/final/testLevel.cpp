#include "testLevel.h"

Player stevePlayer("Steve");
textGameLoop gymLevel(&stevePlayer);

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

std::string gymnasiumText = "The gymnasium is dark and quiet. You experience a strong agoraphobic chill.";

Room entrance = Room("Entrance", entranceText);
Room foyer = Room("Foyer", foyerText);
Room gymnasium = Room("Gymnasium", gymnasiumText);


//entrance functions
void checkPhone(){
	std::string newPrompt = "You're a frugal t-mobile user. As such, you find that in a clutch, you have no bars.";
	entrance.setPrompt(newPrompt);
};


void goToFoyer(){
    //	Player* p = tGL.pGetPlayer();
    //	p->goTo(&foyer);
};

void readComics(){
	std::string comicPrompt = "The safety of your friends may be up in the air but one thing is certain, Eddy Brock's"
	"transformation into Venom is a compelling storyline if ever there was one";
	
    //	Player* p = tGL.pGetPlayer();
    //	Room* currentRoom = p->pGetCurrentLocation();
    //	currentRoom->setPrompt(comicPrompt);
};

//gymnasium functions
void callOutToFriends(){
	gymnasium.setPrompt("You receive only echoes in reply.");
}

//setup helper
void gameInit(){
	entrance.addCommand("check phone", checkPhone);
	entrance.addCommand("go to foyer", goToFoyer);
	entrance.addCommand("read comics", readComics);
	
    //	playerSteve.goTo(&entrance);
}

