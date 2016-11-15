#include "Plot.h"


sf::Vertex Plot::calcPlotPoint_(basic_t xVal)
{
	return sf::Vertex{
		targetView_.convert({xVal, (*func_)(xVal)}),
		parameters.plotColor};
}

///////////////////////////////////////////////////////////////////////////////

Plot::Plot(
	View const & targetView)
	:
	func_		{nullptr},
	funcRange_	{0,0},
	targetView_	{targetView},
	parameters	{Parameters::DEFAULT}
{
}

///////////////////////////////////////////////////////////////////////////////

Plot::Plot(
	x::wrap::ptr<Expr>			func,
	x::range<basic_t> const &	funcRange, 
	View const&					targetView,
	Parameters const&			parameters)
	:
	func_		{func->copy()},
	funcRange_	{funcRange},
	targetView_	{targetView},
	parameters	{parameters}
{
	refresh();
}

///////////////////////////////////////////////////////////////////////////////

//void Plot::draw(sf::RenderTarget & target, sf::RenderStates renderStates) const
//{
//	target.draw(plotPoints_.content(), plotPoints_.size(), sf::PrimitiveType::LinesStrip);
//}

void Plot::display() const
{
	targetView_.window->draw(plotPoints_.data(), plotPoints_.size(), sf::PrimitiveType::LinesStrip);
}

///////////////////////////////////////////////////////////////////////////////

void Plot::fitTarget()
{

}

///////////////////////////////////////////////////////////////////////////////

void Plot::refresh()
{
	funcRange_ = targetView_.calcFuncRange();
	plotPoints_.clear();
	for (auto xi{funcRange_.begin()}; xi; ++xi) {
		plotPoints_.push_back(calcPlotPoint_(*xi));
	}
}

///////////////////////////////////////////////////////////////////////////////

//void Plot::setViewRange(Point const & viewMin, Point const & viewMax)
//{
//	refresh();
//	targetView_.setViewRange(viewMin, viewMax);
//}

Plot::~Plot()
{
	delete func_;
}

///////////////////////////////////////////////////////////////////////////////

Plot::Parameters::Parameters(
	sf::Color const & plotColor,
	sf::Color const & backgroundColor)
	:
	plotColor{plotColor}
{
}

///////////////////////////////////////////////////////////////////////////////

const Plot::Parameters Plot::Parameters::DEFAULT = {
	{255,255,255},
	{0	,0	,0	}};

