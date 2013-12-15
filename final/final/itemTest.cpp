#include "item.h"
#include "testHarness.h"

TEST(itemTest, Item){
	Item shoe = Item("shoe", "A plain pair of brown shoes, barely worn");
	Item axe = Item("axe", "Not a cutting instrument, but rather some \"deoderant\"");
	Item spacesuit = Item("space suit", "Outwardly it appears as a regular three piece suit, but it can also be worn in space");
	
	CHECK_EQUAL(shoe.name, "shoe");
	CHECK_EQUAL(shoe.description, "A plain pair of brown shoes, barely worn");
	
	CHECK_EQUAL(axe.name, "axe");
	CHECK_EQUAL(axe.description, "Not a cutting instrument, but rather some \"deoderant\"")
	
	CHECK_EQUAL(spacesuit.name, "space suit");
	CHECK_EQUAL(spacesuit.description, "Outwardly it appears as a regular three piece suit, but it can also be worn in space")
}