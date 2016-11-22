#include "DragHandler.h"
#include "View.h"
#include "Application.h"


sf::Vector2f DragHandler::relativeMousePos_()
{
	return (sf::Vector2f)sf::Mouse::getPosition(*targetView.window);
}

void DragHandler::initialize_()
{
	parentApplication.addEvent(new KeyPressEvent{
		WKey::LMB,
		true,
		x::Fn<DragHandler, void()>{ this, &DragHandler::hook }
	});

	parentApplication.addEvent(new KeyReleaseEvent{
		WKey::LMB,
		true,
		x::Fn<DragHandler, void()>{ this, &DragHandler::unhook }
	});
}

///////////////////////////////////////////////////////////////////////////////

//void DragHandler::processLockView_(View * view)
//{
//	if (view) {
//		view->setOffset(relativeMousePos_() - dragBeginMousePos_ + dragBeginOffset_);
//	}
//}

///////////////////////////////////////////////////////////////////////////////

DragHandler::DragHandler(View & targetView)
	:
	Service(targetView.parentApplication),
	targetView{targetView},
	dragBeginMousePos_	{0.0f,0.0f},
	dragBeginOffset_	{0.0f,0.0f},
	hooked_{false}
{
	initialize_();
}

void DragHandler::hook()
{
	if (!targetView.window->hasFocus()) return;
	hooked_.on();
	dragBeginMousePos_ = relativeMousePos_();
	dragBeginOffset_ = targetView.getOffset();
}

///////////////////////////////////////////////////////////////////////////////

void DragHandler::unhook()
{
	hooked_.off();
}

///////////////////////////////////////////////////////////////////////////////

void DragHandler::process()
{
	if (hooked_) {
		targetView.setOffset(relativeMousePos_() - dragBeginMousePos_ + dragBeginOffset_);
	}
}

///////////////////////////////////////////////////////////////////////////////

x::error<DragHandler> const DragHandler::ERROR_VIEW_NULLPTR_ = {
	DragHandler::VIEW_NULLPTR, 
	"Cannot hook, target View was nullptr."};

x::error<DragHandler> const DragHandler::ERROR_WINDOW_NO_FOCUS_ = {
	DragHandler::WINDOW_NO_FOCUS,
	"Cannot hook, window has no focus."};