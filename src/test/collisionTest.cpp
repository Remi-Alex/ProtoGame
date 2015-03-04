/**
*	Tests the collisions of elements 
*/
#include "../model/player.h"

TEST(RectanglesNotColliding) {
	Player p1;
	Player p2;
	p2.setPosX(91);
	p2.setPosY(141);
	CHECK(!p1.collides(p2));
	CHECK(!p2.collides(p1));
}

TEST(CollidesX) {
	Player p1;
	Player p2;
	p2.setPosX(25);
	CHECK(p1.collides(p2));
	CHECK(p2.collides(p1));
}

TEST(CollidesY) {
	Player p1;
	Player p2;
	p2.setPosY(50);
	CHECK(p1.collides(p2));
	CHECK(p2.collides(p1));
}

TEST(CollidesDiagNESW) {
	Player p1;
	Player p2;
	p2.setPosY(120);
	p2.setPosX(80);
	CHECK(p1.collides(p2));
	CHECK(p2.collides(p1));
}

TEST(CollidesDiagSENW) {
	Player p1;
	Player p2;
	p1.setPosX(80);
	p2.setPosY(130);
	CHECK(p1.collides(p2));
	CHECK(p2.collides(p1));
}
