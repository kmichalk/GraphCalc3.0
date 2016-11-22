#include "DrawTaskHandler.h"
#include "loops.h"
#include "View.h"


void DrawTaskHandler::process()
{
	bool viewChanged = targetView.changed;
	foreach(task, tasks_) {
		if (viewChanged) task->refresh();
		task->draw(targetView);
	}
	targetView.display();
	targetView.clear();
	targetView.clearFlags();
}

DrawTaskHandler::DrawTaskHandler(View & targetView)
	:
	Service(targetView.parentApplication),
	targetView{targetView}
{
}

void DrawTaskHandler::addTask(DrawTask * task)
{
	tasks_.push_back(task);
}

void DrawTaskHandler::clear()
{
	tasks_.erase<x::PTR_DELETE>();
}

DrawTaskHandler::~DrawTaskHandler()
{
	clear();
}
