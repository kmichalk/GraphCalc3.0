#ifndef _CROSS_CURSOR_H_
#define _CROSS_CURSOR_H_

#include "SimpleCursor.h"


class CrossCursor: public SimpleCursor
{
protected:
	sf::RectangleShape verticalLine_;
	sf::RectangleShape horizontalLine_;

public:
	struct Parameters
	{
		static const Parameters DEFAULT;
		sf::Color color;
		float thickness;

		Parameters(sf::Color const& color, float thickness);
	};

	Parameters parameters;

	CrossCursor(
		View& targetView, 
		Parameters const& parameters = Parameters::DEFAULT);

	virtual void draw(View& targetView) override;
	virtual void refresh() override;
};

#endif //_CROSS_CURSOR_H_
