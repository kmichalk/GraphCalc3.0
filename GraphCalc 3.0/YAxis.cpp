#include "YAxis.h"
#include "View.h"
#include "Grid.h"
#include "Application.h"

void YAxis::actualizeCache_()
{
	cache_.windowSize = (sf::Vector2f)parentGrid.targetView.window->getSize();
	cache_.divAmount = abs(cache_.windowSize.y /
		(parentGrid.targetView.scale.y * parameters.spacing)) + 1;
	cache_.crdBegin = parentGrid.targetView.getCrdBegin();
	cache_.viewOffset = parentGrid.targetView.getOffset();
	cache_.dispSpacing = abs(parameters.spacing * parentGrid.targetView.scale.y);
	cache_.beginPos = fmod(cache_.viewOffset.y + cache_.crdBegin.y, cache_.dispSpacing);
	if (cache_.beginPos < 0) cache_.beginPos += cache_.dispSpacing;
	cache_.beginNum = ceil((
		cache_.crdBegin.y + cache_.viewOffset.y) / parentGrid.targetView.scale.y);// ,
		//parameters.spacing);
	cache_.pos = cache_.viewOffset.x + cache_.crdBegin.x;
}

///////////////////////////////////////////////////////////////////////////////

void YAxis::refreshAxis_()
{
	line_.setSize({parameters.axisThickness, cache_.windowSize.y});
	line_.setOrigin({parameters.axisThickness / 2, 0});
	line_.setPosition({cache_.pos, 0});
	
}

///////////////////////////////////////////////////////////////////////////////

void YAxis::refreshNumbers_()
{
	x::range<double> nearZero{-0.1*abs(parameters.spacing), 0.1*abs(parameters.spacing)};
	sf::Text number{
		"",
		parentGrid.targetView.parentApplication.parameters.font,
		parameters.numberSize};

	double revFlag = x::sgn(parentGrid.targetView.scale.y);
	numbers_.clear();
	for (size_t yi = 0; yi < cache_.divAmount; ++yi) {
		double value = revFlag*(cache_.beginNum + parameters.spacing*yi);
		if (!nearZero.contains(value)) {
			number.setString(formatNumber_(std::to_string(value)));
			number.setPosition({cache_.pos, cache_.beginPos + (float)cache_.dispSpacing*yi});
			numbers_.push_back(number);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

void YAxis::refreshGridLines_()
{
	gridLines_.clear();

	sf::RectangleShape line{{cache_.windowSize.x, parameters.gridLinesThickness}};
	for (size_t yi = 0; yi < cache_.divAmount; ++yi) {
		line.setPosition(0.0f, cache_.beginPos + (float)cache_.dispSpacing * (float)yi);
		line.setFillColor(parameters.gridLinesColor);
		gridLines_.push_back(line);
	}
}

///////////////////////////////////////////////////////////////////////////////

YAxis::YAxis(
	Grid const &		parent,
	Parameters const &	parameters)
	:
	Axis{parent, parameters}
{

}
