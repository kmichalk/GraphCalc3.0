#ifndef _GRID_H_
#define _GRID_H_

#include "xvector.h"
#include "SFML\Graphics.hpp"
#include "types.h"
#include "DrawTask.h"
#include "XAxis.h"
#include "YAxis.h"


class Grid:
	public DrawTask
{
	XAxis xAxis_;
	YAxis yAxis_;

public:
	View const& targetView;


	Grid(View const& targetView);

	virtual void draw(View& targetView) override;
	virtual void refresh() override;
};

#endif //_GRID_H_
