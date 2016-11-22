#ifndef _DRAG_HANDLER_H_
#define _DRAG_HANDLER_H_

#include "SFML\Graphics.hpp"
#include "Service.h"
#include "error.h"
#include "flag.h"


class View;
class Application;

class DragHandler:
	public Service
{
	static x::error<DragHandler> const ERROR_VIEW_NULLPTR_;
	static x::error<DragHandler> const ERROR_WINDOW_NO_FOCUS_;

	sf::Vector2f dragBeginMousePos_;
	sf::Vector2f dragBeginOffset_;
	x::flag hooked_;

	sf::Vector2f relativeMousePos_();
	void initialize_();
	//void processLockView_(View* view);

public:
	View& targetView;

	enum ErrorNum
	{
		VIEW_NULLPTR, WINDOW_NO_FOCUS
	};

	DragHandler(View& targetView);

	void hook();
	void unhook();
	virtual void process() override;
};

#endif //_DRAG_HANDLER_H_
