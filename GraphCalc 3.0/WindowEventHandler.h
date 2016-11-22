#ifndef _WINDOW_EVENT_HANDLER_H_
#define _WINDOW_EVENT_HANDLER_H_

#include "Service.h"


class View;

class WindowEventHandler:
	public Service
{
	void readjustView_() const;

public:
	View& targetView;

	WindowEventHandler(View& targetView);

	virtual void process() override;
};

#endif //_WINDOW_EVENT_HANDLER_H_
