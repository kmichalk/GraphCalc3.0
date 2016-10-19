#ifndef _PLOT_H_
#define _PLOT_H_

#include "xvector.h"
#include "CoordinateConverter.h"
#include "mathfn.h"
#include "wrap.h"

class Plot:
	public sf::Drawable
{
	using Func = x::math::expr<basic_t>;

	x::vector<Point> funcValues_;
	x::vector<sf::Vertex> plotPoints_;
	x::range<basic_t> funcRange_;
	Func* func_;

	sf::Vertex calcPlotPoint_(basic_t xVal);

public:
	struct Parameters
	{
		sf::Color color;

		static const Parameters DEFAULT;

		Parameters(sf::Color const& color);
	};

	ViewConverter targetView;
	Parameters parameters;

	Plot();

	Plot(
		x::wrap::ptr<Func> func,
		x::range<basic_t> const & funcRange,
		ViewConverter const& targetView,
		Parameters const& parameters = Parameters::DEFAULT);

	virtual void draw(
		sf::RenderTarget&	target,
		sf::RenderStates	renderStates = sf::RenderStates::Default) const override;
	
	void refresh();
};

#endif //_PLOT_H_