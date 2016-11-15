#include "Grid.h"
#include "View.h"
#include "loops.h"


Grid::Grid(View const& targetView)
	:
	targetView{targetView},
	xAxis_{*this},
	yAxis_{*this}
{
}

///////////////////////////////////////////////////////////////////////////////

void Grid::draw(View & targetView)
{
	if (!visible) return;

	//refresh();
	/*foreach(line, verticalLines_){	
		targetView.window->draw(*line);
	}
	foreach(line, horizontalLines_){
		targetView.window->draw(*line);
	}*/
	xAxis_.draw(targetView);
	yAxis_.draw(targetView);
}

///////////////////////////////////////////////////////////////////////////////

void Grid::refresh()
{
	if (!visible) return;

	xAxis_.refresh();
	yAxis_.refresh();
}
