#include "Plot.h"

sf::Vertex Plot::calcPlotPoint_(basic_t xVal)
{
	return sf::Vertex{
		targetView({xVal, (*func_)(xVal)}),
		parameters.color};
}

Plot::Plot():
	targetView{nullptr},
	func_{nullptr}
{
}

Plot::Plot(
	x::wrap::ptr<Func> func,
	x::range<basic_t> const & funcRange, 
	ViewConverter const& targetView,
	Parameters const& parameters)
	:
	func_{func->copy()},
	funcRange_{funcRange},
	targetView{targetView},
	parameters{parameters}
{
}

void Plot::draw(sf::RenderTarget & target, sf::RenderStates renderStates) const
{
	target.draw(plotPoints_.content(), plotPoints_.size(), sf::PrimitiveType::LinesStrip);
}

void Plot::refresh()
{
	plotPoints_.clear();
	for (auto xi{funcRange_.begin()}; xi; ++xi) {
		plotPoints_.push_back(calcPlotPoint_(*xi));
	}
}

Plot::Parameters::Parameters(
	sf::Color const & color)
	:
	color{color}
{
}

const Plot::Parameters Plot::Parameters::DEFAULT = {{255,255,255}};