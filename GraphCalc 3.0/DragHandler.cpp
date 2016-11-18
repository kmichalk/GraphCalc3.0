#include "DragHandler.h"
#include "View.h"


sf::Vector2f DragHandler::relativeMousePos_()
{
	return (sf::Vector2f)sf::Mouse::getPosition(*targetView_->window);
}

///////////////////////////////////////////////////////////////////////////////

//void DragHandler::processLockView_(View * view)
//{
//	if (view) {
//		view->setOffset(relativeMousePos_() - dragBeginMousePos_ + dragBeginOffset_);
//	}
//}

///////////////////////////////////////////////////////////////////////////////

DragHandler::DragHandler(Application& parent)
	:
	ServiceHandler		(parent),
	targetView_			{nullptr},
	dragBeginMousePos_	{0.0f,0.0f},
	dragBeginOffset_	{0.0f,0.0f},
	targetLock_			{false}
{
}

///////////////////////////////////////////////////////////////////////////////

void DragHandler::hook(View * targetView)
{
	if (!targetView) throw ERROR_VIEW_NULLPTR_;
	if (!targetView->window->hasFocus()) return;
		//throw ERROR_WINDOW_NO_FOCUS_;

	targetView_ = targetView;
	dragBeginMousePos_ = relativeMousePos_();
	dragBeginOffset_ = targetView_->getOffset();
}

///////////////////////////////////////////////////////////////////////////////

void DragHandler::unhook()
{
	/*unsigned count{0};
	while (targetLock_) {
		++count;
	}
	std::cout<< count<<std::endl;*/
	targetView_ = nullptr;
}

///////////////////////////////////////////////////////////////////////////////

void DragHandler::process()
{
	//targetLock_ = true;
	auto targetViewLock = targetView_;
	if (targetViewLock) {
		targetViewLock->setOffset(relativeMousePos_() - dragBeginMousePos_ + dragBeginOffset_);
	}
	//targetLock_ = false;
	//else throw x::error<DragHandler>{};
}

///////////////////////////////////////////////////////////////////////////////

x::error<DragHandler> const DragHandler::ERROR_VIEW_NULLPTR_ = {
	DragHandler::VIEW_NULLPTR, 
	"DragHandler: Cannot hook, target View was nullptr."};

x::error<DragHandler> const DragHandler::ERROR_WINDOW_NO_FOCUS_ = {
	DragHandler::WINDOW_NO_FOCUS,
	"DragHandler: Cannot hook, window has no focus."};