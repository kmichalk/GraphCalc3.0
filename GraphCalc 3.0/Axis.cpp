#include "Axis.h"
#include "Grid.h"
#include "View.h"
#include "Application.h"


std::string Axis::formatNumber_(std::string const & number)
{
	return (std::string)x::string{number}.trim_decimal();
}

void Axis::drawNumbers_()
{
	foreach(number, numbers_)
		parentGrid.targetView.window->draw(*number);
}

///////////////////////////////////////////////////////////////////////////////

void Axis::drawGridLines_()
{
	foreach(line, gridLines_)
		parentGrid.targetView.window->draw(*line);
}

///////////////////////////////////////////////////////////////////////////////

Axis::Axis(
	Grid const &		parentGrid,
	Parameters const &	parameters)
	:
	parentGrid	{parentGrid},
	parameters	{parameters},
	font_		{}
{
	line_.setFillColor(parameters.axisColor);
}

///////////////////////////////////////////////////////////////////////////////

void Axis::refresh()
{
	actualizeCache_();
	refreshAxis_();
	refreshNumbers_();
	refreshGridLines_();
}

///////////////////////////////////////////////////////////////////////////////

void Axis::draw(View & tagretView)
{
	if (!visible) return;
	//refresh();
	drawGridLines_();
	drawNumbers_();
	parentGrid.targetView.window->draw(line_);
}

///////////////////////////////////////////////////////////////////////////////

Axis::Parameters::Parameters(
	sf::Color	axisColor, 
	sf::Color	gridLinesColor,
	float		axisThickness,
	float		gridLinesThickness,
	unsigned	numberSize,
	float		spacing)
	:
	axisColor			{axisColor},
	gridLinesColor		{gridLinesColor},
	axisThickness		{axisThickness},
	gridLinesThickness	{gridLinesThickness},
	numberSize			{numberSize},
	spacing				{spacing}
{
}

const Axis::Parameters Axis::Parameters::DEFAULT = {{170,170,170}, {70,70,70}, 2.0f, 1.0f, 12, 1.0};