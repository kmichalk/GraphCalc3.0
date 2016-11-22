#ifndef _DRAW_TASK_HANDLER_H_
#define _DRAW_TASK_HANDLER_H_

#include "Service.h"
#include "DrawTask.h"
#include "xvector.h"


class View;

class DrawTaskHandler:
	public Service
{
	x::vector<DrawTask*> tasks_;

public:
	View& targetView;

	DrawTaskHandler(View& targetView);

	virtual void process() override;
	void addTask(DrawTask* task);
	void clear();

	~DrawTaskHandler();
};

#endif //_DRAW_TASK_HANDLER_H_
