#ifndef _WINDOW_EVENT_HANDLER_H_
#define _WINDOW_EVENT_HANDLER_H_

#include "Service.h"


class View;

class WindowEventHandler:
	public Service
{
	void readjustView_() const;

public:
	View& parentView;

	WindowEventHandler(View& parentView);

	virtual void process() override;
};

#endif //_WINDOW_EVENT_HANDLER_H_
