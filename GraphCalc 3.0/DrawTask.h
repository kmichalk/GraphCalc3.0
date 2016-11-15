#ifndef _DRAW_TASK_H_
#define _DRAW_TASK_H_

#include "flag.h"


class View;

class DrawTask
{
public:
	x::flag visible;

	virtual void refresh() abstract;
	virtual void draw(View& targetView) abstract;
};

#endif //_DRAW_TASK_H_
