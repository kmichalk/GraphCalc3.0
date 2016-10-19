#ifndef _VIEW_CONVERTER_H_
#define _VIEW_CONVERTER_H_

#include "SFML\Graphics.hpp"
#include "types.h"

class ViewConverter
{
	sf::RenderTarget const* target_;
	Point viewMin_;
	Point viewMax_;
	bool revY_;

public:
	ViewConverter(
		sf::RenderTarget const* target,
		Point viewMin = {0.0,0.0},
		Point viewMax = {0.0,0.0},
		bool revY_ = false);

	ViewConverter& operator=(ViewConverter const& other);
	sf::Vector2f operator()(Point pos) const;
	void setTarget(sf::RenderTarget const* target);
	void setViewRange(Point viewMin, Point viewMax);
	void setReverseY(bool value);
};

#endif //_COORDINATE_CONVERTER_H_
