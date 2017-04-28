#include "PlotHandler.h"
#include "loops.h"


PlotHandler::PlotHandler(
	View const & targetView)
	:
	targetView_{targetView},
	plots_{DEFAULT_PLOTS_SIZE_}
{
}

///////////////////////////////////////////////////////////////////////////////

void PlotHandler::createPlot(
	Expr* func, 
	Plot::Parameters const & parameters) throw(x::error<PlotHandler>)
{
	if (!func) throw x::error<PlotHandler>{0, "Function expression was nullptr.\n"}; 
	plots_.push_back(new Plot{func, targetView_.calcFuncRange(), targetView_, parameters});
}

void PlotHandler::createPlot(x::vector<CommandAnalizer::ParseResult> const & plots)
{
	const_foreach(plot, plots){
		createPlot(plot->func, {plot->funcName, Plot::Parameters::DEFAULT.color});
	}
}

///////////////////////////////////////////////////////////////////////////////

void PlotHandler::draw(View & targetView)
{
	bool viewChanged = targetView_.changed;
	for (auto plot{plots_.begin()}; plot; ++plot) {
		if (viewChanged) plot->refresh();
		plot->display();
	}
}

x::result<Plot*> PlotHandler::findFunc(x::string const name)
{
	return plots_.find_by([&name](Plot* p) {return p->parameters.funcName == name; });
}

void PlotHandler::display()
{
	/*if (targetView_.changed()) {
		refresh();
	}*/
	bool viewChanged = targetView_.changed;
	for (auto plot{plots_.begin()}; plot; ++plot) {
		if (viewChanged) plot->refresh();
		plot->display();
	}
	targetView_.clearFlags();
}

///////////////////////////////////////////////////////////////////////////////

void PlotHandler::refresh()
{
	for (auto plot{plots_.begin()}; plot; ++plot) {
		plot->refresh();
	}
}

void PlotHandler::clear()
{
	plots_.clear<x::PTR_DELETE>();
}
