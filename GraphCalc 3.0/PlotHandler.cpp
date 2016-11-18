#include "PlotHandler.h"


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
	Plot::Parameters const & parameters)
{
	if (!func) throw x::error<PlotHandler>{0, "Function expression was nullptr.\n"}; 
	plots_.push_back(new Plot{func, targetView_.calcFuncRange(), targetView_, parameters});
}

///////////////////////////////////////////////////////////////////////////////

void PlotHandler::draw(View & targetView)
{
	bool viewChanged = targetView_.changed();
	for (auto plot{plots_.begin()}; plot; ++plot) {
		if (viewChanged) plot->refresh();
		plot->display();
	}
}

void PlotHandler::display()
{
	/*if (targetView_.changed()) {
		refresh();
	}*/
	bool viewChanged = targetView_.changed();
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
	plots_.erase<x::PTR_DELETE>();
}
