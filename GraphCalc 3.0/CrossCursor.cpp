#include "CrossCursor.h"
#include "View.h"


void CrossCursor::draw(View & targetView)
{
	refresh();
	targetView.window->draw(verticalLine_);
	targetView.window->draw(horizontalLine_);
}

void CrossCursor::refresh()
{
	refreshPosition_();
	sf::Vector2f windowSize = (sf::Vector2f)targetView.window->getSize();
	verticalLine_.setPosition(0, position_.y);
	verticalLine_.setSize({windowSize.x, parameters.thickness});
	horizontalLine_.setPosition(position_.x, 0);
	horizontalLine_.setSize({parameters.thickness, windowSize.y});
}

CrossCursor::CrossCursor(
	View & targetView,
	Parameters const& parameters)
	:
	SimpleCursor(targetView),
	parameters{parameters}
{
	verticalLine_.setFillColor(parameters.color);
	horizontalLine_.setFillColor(parameters.color);
}



CrossCursor::Parameters::Parameters(
	sf::Color const & color,
	float thickness)
	:
	color{color},
	thickness{thickness}
{
}

const CrossCursor::Parameters CrossCursor::Parameters::DEFAULT = {
	{150,180,85},
	1.0f
};