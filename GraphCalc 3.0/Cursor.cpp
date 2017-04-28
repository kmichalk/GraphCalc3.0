#include "Cursor.h"
#include "View.h"


void Cursor::refreshPosition_()
{
	position_ = (sf::Vector2f)sf::Mouse::getPosition(*targetView.window);
}

Cursor::Cursor(
	View & targetView)
	:
	targetView{targetView}
{
}

