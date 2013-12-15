#include "point.h"
#include "testHarness.h"

TEST(pointTest, point){
	Point a = Point(1, 1);
	Point b = Point(2, 2);
	Point c = Point(3, 3);
	
	CHECK_EQUAL(1, a.x);
	CHECK_EQUAL(1, a.y);
	CHECK_EQUAL(2, b.x);
	CHECK_EQUAL(2, b.y);
	CHECK_EQUAL(3, c.x);
	CHECK_EQUAL(3, c.y);
	
	a.x += 1;
	a.y += 1;
	b.x += 1;
	b.y += 1;
	c.x += 1;
	c.y += 1;
	
	CHECK_EQUAL(2, a.x);
	CHECK_EQUAL(2, a.y);
	CHECK_EQUAL(3, b.x);
	CHECK_EQUAL(3, b.y);
	CHECK_EQUAL(4, c.x);
	CHECK_EQUAL(4, c.y);
}