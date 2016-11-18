#ifndef _PLOT_HANDLER_H_
#define _PLOT_HANDLER_H_

#include "Plot.h"


class PlotHandler:
	public DrawTask
{
	static constexpr size_t DEFAULT_PLOTS_SIZE_ = 5;

	View const& targetView_;
	x::vector<Plot*> plots_;
	bool needRefresh_;

public:
	PlotHandler(
		View const& targetView);

	void createPlot(
		Expr* func,
		Plot::Parameters const& parameters = Plot::Parameters::DEFAULT);

	virtual void draw(View& targetView) override;
	void display();
	void refresh();
	void clear();
};

#endif //_PLOT_HANDLER_H_
