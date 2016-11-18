#ifndef _DRAG_HANDLER_H_
#define _DRAG_HANDLER_H_

#include "SFML\Graphics.hpp"
#include "ServiceHandler.h"
#include "error.h"


class View;

class DragHandler:
	public ServiceHandler
{
	static x::error<DragHandler> const ERROR_VIEW_NULLPTR_;
	static x::error<DragHandler> const ERROR_WINDOW_NO_FOCUS_;

	View* targetView_;
	sf::Vector2f dragBeginMousePos_;
	sf::Vector2f dragBeginOffset_;
	volatile bool targetLock_;

	sf::Vector2f relativeMousePos_();
	//void processLockView_(View* view);

public:
	enum ErrorNum
	{
		VIEW_NULLPTR, WINDOW_NO_FOCUS
	};

	DragHandler(Application& parent);

	void hook(View* targetView);
	void unhook();
	virtual void process() override;
};

#endif //_DRAG_HANDLER_H_
