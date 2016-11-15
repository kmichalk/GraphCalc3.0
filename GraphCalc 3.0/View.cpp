#include "View.h"
#include "error.h"

//View::View(
//	sf::RenderTarget const * target, 
//	Point	viewMin, 
//	Point	viewMax)
//	:
//	target_		{target},
//	viewMin_	{x::crdmin(viewMin,viewMax)},
//	viewMax_	{x::crdmax(viewMin,viewMax)},
//	offset_		{0.0f,0.0f},
//	revY_		{revY_}
//{
//}

View::View(Application const& parentApp)
	:
	parentApp		{parentApp},
	window			{nullptr},
	scale			{DEFAULT_SCALE},
	crdBegin_		{0.0f, 0.0f},
	calcDensity_	{DEFAULT_CALC_DENSITY},
	changed_		{false}
{
}

View::View(
	Application const& parentApp,
	sf::RenderWindow*	window,
	Size				scale)
	:
	parentApp		{parentApp},
	window			{window},
	scale			{scale},
	crdBegin_		{0.0f, (float)window->getSize().y},
	calcDensity_	{DEFAULT_CALC_DENSITY},
	changed_		{false}
{
}

///////////////////////////////////////////////////////////////////////////////

//View & View::operator=(View const & other)
//{
//	renderTarget = other.renderTarget;
//	scale_ = other.scale_;
//	/*xScale_ = other.xScale_;
//	yScale_ = other.yScale_;*/
//	//viewMin_ = other.viewMin_;
//	//viewMax_ = other.viewMax_;
//	//revY_ = other.revY_;
//	return *this;
//}

void View::init(Parameters const & parameters)
{
	if (window) ALREADY_INITIALIZED_ERROR;
	window = new sf::RenderWindow{parameters.videoMode, parameters.winName};
	scale = parameters.scale;
	crdBegin_ = {0.0f, (float)window->getSize().y};
	backgroundColor_ = parameters.backgroundColor;
}

void View::display()
{
	if (window)
		window->display();
}

void View::clear()
{
	if (window)
		window->clear(backgroundColor_);
}

sf::Vector2f View::convert(Point pos) const
{
	/*if (!target_) {
	throw x::error<CoordinatesConverter>{};
	}*/

	return crd_cast<sf::Vector2f>(multCrd(pos, scale)) + offset_ + crdBegin_;
	/*	return sf::Vector2f{
	float((pos.x) / (viewMax_.x - viewMin_.x))*targetSize.x,
	float((pos.y - viewMin_.y) / (viewMax_.y - viewMin_.y))*targetSize.y}
	+offset_;*/
}

///////////////////////////////////////////////////////////////////////////////

//sf::Vector2f View::convert(Point pos) const
//{
//	/*if (!target_) {
//		throw x::error<CoordinatesConverter>{};
//	}*/
//	auto targetSize = sf::Vector2f(target_->getSize());
//	if (revY_) {
//		return sf::Vector2f{
//			float((pos.x-viewMin_.x)/(viewMax_.x - viewMin_.x))*targetSize.x,
//			float(-(pos.y-viewMin_.y)/(viewMax_.y - viewMin_.y))*targetSize.y + targetSize.y} 
//		;
//	}
//	else {
//		return sf::Vector2f{
//			float((pos.x-viewMin_.x)/(viewMax_.x - viewMin_.x))*targetSize.x,
//			float((pos.y-viewMin_.y)/(viewMax_.y - viewMin_.y))*targetSize.y}
//		+ offset_;
//	}
//}

//void View::setTarget(sf::RenderWindow * target)
//{
//	if (!target) throw x::error<View>{};
//	window = target;
//	changed_ = true;
//}

///////////////////////////////////////////////////////////////////////////////

void View::setViewRange(Point const & viewMin, Point const & viewMax)
{
	//viewMin_ = x::crdmin(viewMin, viewMax);
	//viewMax_ = x::crdmax(viewMin, viewMax);
}

///////////////////////////////////////////////////////////////////////////////

//void View::setReverseY(bool value)
//{
//	scale_.y = value ? -abs(scale_.y) : abs(scale_.y);
//}

x::range<basic_t> View::calcFuncRange() const
{
	x::range<basic_t> funcRange{
		(-offset_.x) / scale.x,
		(window->getSize().x - offset_.x) / scale.x};
	return funcRange.divide(window->getSize().x * calcDensity_ + 1);
}

///////////////////////////////////////////////////////////////////////////////

void View::move(sf::Vector2f vec)
{
	offset_ += vec;
	changed_ = true;
}

///////////////////////////////////////////////////////////////////////////////

void View::setOffset(sf::Vector2f offset)
{
	offset_ = offset;
	changed_ = true;
}

///////////////////////////////////////////////////////////////////////////////

sf::Vector2f View::getOffset() const
{
	return offset_;
}

///////////////////////////////////////////////////////////////////////////////

sf::Vector2f View::getCrdBegin() const
{
	return crdBegin_;
}

///////////////////////////////////////////////////////////////////////////////

void View::center()
{
	offset_ = sf::Vector2f(window->getSize()) / 2.0f;
	x::negate(offset_.y);
	changed_ = true;
}

///////////////////////////////////////////////////////////////////////////////

void View::setCalcDensity(double value)
{
	calcDensity_ = value;
}

///////////////////////////////////////////////////////////////////////////////

bool View::changed() const
{
	return changed_;
}

///////////////////////////////////////////////////////////////////////////////

void View::clearFlags() const
{
	changed_ = false;
}

View::~View()
{
	if (window) {
		window->close();
		delete window;
	}
}

View::Parameters::Parameters(
	sf::VideoMode const& videoMode,
	char const * winName,
	Size const& scale,
	sf::Color backgroundColor)
	:
	videoMode{videoMode},
	winName{winName},
	scale{scale},
	backgroundColor{backgroundColor}
{
}


const x::error<View> View::ALREADY_INITIALIZED_ERROR = 
	{View::ALREADY_INITIALIZED, "Window already initialized."};

const sf::Color View::DEFAULT_BACKGROUND_COLOR = {20,20,20};

const View::Parameters View::Parameters::DEFAULT =
	{{800,600},"GraphCalc 3.0", View::DEFAULT_SCALE,View::DEFAULT_BACKGROUND_COLOR};