#ifndef _PLOT_H_
#define _PLOT_H_

#include "xvector.h"
#include "View.h"
#include "wrap.h"
#include "DrawTask.h"


class Plot
{
	friend class PlotHandler;

	x::vector<Point> funcValues_;
	x::vector<sf::Vertex> plotPoints_;
	x::range<basic_t> funcRange_;
	Expr* func_;
	View const& targetView_;

	sf::Vertex calcPlotPoint_(basic_t xVal);

public:
	struct Parameters
	{
		static const Parameters DEFAULT;

		sf::Color plotColor;
		sf::Color backgroundColor;

		Parameters(
			sf::Color const& plotColor,
			sf::Color const& backgroundColor = DEFAULT.backgroundColor);
	};

	Parameters parameters;

	Plot(
		View const& targetView);

	Plot(
		x::wrap::ptr<Expr>			func,
		x::range<basic_t> const&	funcRange,
		View const&					targetView,
		Parameters const&			parameters = Parameters::DEFAULT);

	/*virtual void draw(
		sf::RenderTarget&	target,
		sf::RenderStates	renderStates = sf::RenderStates::Default) const override;*/
	void display() const;
	void fitTarget();
	void refresh();
	//void setViewRange(Point const& viewMin, Point const& viewMax);

	~Plot();
};

#endif //_PLOT_H_