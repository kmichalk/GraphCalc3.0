#include "XAxis.h"
#include "View.h"
#include "Grid.h"
#include "Application.h"

void XAxis::actualizeCache_()
{
	cache_.windowSize = (sf::Vector2f)parentGrid.targetView.window->getSize();
	cache_.divAmount = abs(cache_.windowSize.x /
		(parentGrid.targetView.scale.x * parameters.spacing)) + 1;
	cache_.crdBegin = parentGrid.targetView.getCrdBegin();
	cache_.viewOffset = parentGrid.targetView.getOffset();
	cache_.dispSpacing = abs(parameters.spacing * parentGrid.targetView.scale.x);
	cache_.beginPos = fmod(cache_.viewOffset.x + cache_.crdBegin.x, cache_.dispSpacing);
	if (cache_.beginPos < 0) cache_.beginPos += cache_.dispSpacing;
	cache_.beginNum = ceil((
		cache_.crdBegin.x - cache_.viewOffset.x) / parentGrid.targetView.scale.x);// ,
		//parameters.spacing);
	cache_.pos = cache_.viewOffset.y + cache_.crdBegin.y;
}

///////////////////////////////////////////////////////////////////////////////

void XAxis::refreshAxis_()
{
	line_.setSize({cache_.windowSize.x, parameters.axisThickness});
	line_.setOrigin({0, parameters.axisThickness / 2});
	line_.setPosition({0, cache_.pos});
}

///////////////////////////////////////////////////////////////////////////////

void XAxis::refreshNumbers_()
{
	x::range<double> nearZero{-0.1*abs(parameters.spacing), 0.1*abs(parameters.spacing)};
	sf::Text number{
		"",
		parentGrid.targetView.parentApplication.parameters.font,
		parameters.numberSize};

	double revFlag = x::sgn(parentGrid.targetView.scale.x);
	numbers_.clear();
	for (size_t xi = 0; xi < cache_.divAmount; ++xi) {
		double value = revFlag*(cache_.beginNum + parameters.spacing*xi);
		if (!nearZero.contains(value)) {
			number.setString(formatNumber_(std::to_string(value)));
			number.setPosition({cache_.beginPos + (float)cache_.dispSpacing*xi, cache_.pos});
			numbers_.push_back(number);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

void XAxis::refreshGridLines_()
{
	gridLines_.clear();
	
	sf::RectangleShape line{{parameters.gridLinesThickness, cache_.windowSize.y}};
	for (size_t xi = 0; xi < cache_.divAmount; ++xi) {
		line.setPosition(cache_.beginPos + (float)cache_.dispSpacing * (float)xi, 0.0f);
		line.setFillColor(parameters.gridLinesColor);
		gridLines_.push_back(line);
	}
}

///////////////////////////////////////////////////////////////////////////////

XAxis::XAxis(
	Grid const &		parent, 
	Parameters const &	parameters)
	:
	Axis{parent, parameters}
{
	
}
