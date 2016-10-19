#include "CoordinateConverter.h"
#include "error.h"

ViewConverter::ViewConverter(
	sf::RenderTarget const * target, 
	Point viewMin, 
	Point viewMax, 
	bool revY_)
	:
	target_{target},
	viewMin_{x::min(viewMin,viewMax)},
	viewMax_{x::max(viewMin,viewMax)},
	revY_{revY_}
{
}

ViewConverter & ViewConverter::operator=(ViewConverter const & other)
{
	target_ = other.target_;
	viewMin_ = other.viewMin_;
	viewMax_ = other.viewMax_;
	revY_ = other.revY_;
	return *this;
}

sf::Vector2f ViewConverter::operator()(Point pos) const
{
	/*if (!target_) {
		throw x::error<CoordinatesConverter>{};
	}*/
	auto targetSize = sf::Vector2f(target_->getSize());
	if (revY_) {
		return{
			float((pos.x-viewMin_.x)/(viewMax_.x - viewMin_.x))*targetSize.x,
			float(-(pos.y-viewMin_.y)/(viewMax_.y - viewMin_.y))*targetSize.y + targetSize.y};
	}
	else {
		return{
			float((pos.x-viewMin_.x)/(viewMax_.x - viewMin_.x))*targetSize.x,
			float((pos.y-viewMin_.y)/(viewMax_.y - viewMin_.y))*targetSize.y};
	}
}

void ViewConverter::setTarget(sf::RenderTarget const * target)
{
	if (!target) throw x::error<ViewConverter>{};
	target_ = target;
}

void ViewConverter::setViewRange(Point viewMin, Point viewMax)
{
	viewMin_ = x::min(viewMin, viewMax);
	viewMax_ = x::max(viewMin, viewMax);
}

void ViewConverter::setReverseY(bool value)
{
	revY_ = value;
}
