#ifndef _AXIS_H_
#define _AXIS_H_

#include "SFML\Graphics.hpp"
#include "types.h"
#include "xvector.h"
#include "DrawTask.h"
#include "xstring.h"


class Grid;

class Axis:
	public DrawTask
{
public:
	struct Parameters
	{
		static const Parameters DEFAULT;

		sf::Color axisColor;
		sf::Color gridLinesColor;
		float axisThickness;
		float gridLinesThickness;
		unsigned numberSize;
		float spacing;

		Parameters(
			sf::Color axisColor,
			sf::Color gridLinesColor,
			float axisThickness,
			float gridLinesThickness,
			unsigned numberSize,
			float spacing);
	};

protected:
	struct OptimizerCache
	{
		sf::Vector2f	windowSize;
		sf::Vector2f	crdBegin;
		sf::Vector2f	viewOffset;
		float			beginPos;
		size_t			divAmount;
		float			dispSpacing;
		double			beginNum;
		float			pos;
	};

	OptimizerCache cache_;

	sf::RectangleShape line_;
	x::vector<sf::Text> numbers_;
	x::vector<sf::RectangleShape> gridLines_;
	sf::Font const& font_;

	static std::string formatNumber_(std::string const& number);

	virtual void actualizeCache_() abstract;
	virtual void refreshAxis_() abstract;
	virtual void refreshNumbers_() abstract;
	virtual void refreshGridLines_() abstract;
	
	void drawNumbers_();
	void drawGridLines_();

public:
	Grid const& parentGrid;
	Parameters parameters;

	Axis(
		Grid const& parentGrid,
		Parameters const& parameters);

	virtual void refresh() override;
	virtual void draw(View& tagretView) override;
};

#endif //_AXIS_H_
