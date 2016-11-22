#include "DrawingHandler.h"
#include "Application.h"


DrawingHandler::DrawingHandler(
	Application& parent,
	View& view,
	//std::initializer_list<DrawTask*> tasks,
	double drawPeriod)
	:
	TimedProcess{drawPeriod},
	AppComponent{parent},
	view_{view}
	//drawTasks_{tasks}
{
}

///////////////////////////////////////////////////////////////////////////////

void DrawingHandler::processWindowEvents_()
{
	if (view_.window->pollEvent(windowEvent_)) {
		if (windowEvent_.type == sf::Event::EventType::Closed) {
			view_.window->close();
		}
		if (windowEvent_.type == sf::Event::EventType::Resized) {
			readjustView_();
		}
	}
}

void DrawingHandler::readjustView_()
{
	view_.window->setView(sf::View{
		(sf::Vector2f)view_.window->getSize() / 2.0f ,
		(sf::Vector2f)view_.window->getSize()});
}

///////////////////////////////////////////////////////////////////////////////

bool DrawingHandler::setFont(
	std::string fileName,
	unsigned fontSize)
{
	return true;
	//fontSize_ = fontSize;
	//return font_.loadFromFile(fileName);
}

void DrawingHandler::addDrawTask(DrawTask * task)
{
	if (task)
		drawTasks_.push_back(task);
}

///////////////////////////////////////////////////////////////////////////////

void DrawingHandler::process()
{
	parentApplication.initView();
	view_.center();
	view_.setOffset({400,-300});
	TimedProcess::process();
}

//  ,   ,
//  (*,*)
// ((   ))
//   " "

///////////////////////////////////////////////////////////////////////////////

void DrawingHandler::task()
{
	bool viewChanged = view_.changed();
	for (auto&& task : drawTasks_) {
		if (viewChanged) task->refresh();
		task->draw(view_);
	}
	view_.display();
	view_.clear();
	processWindowEvents_();
	view_.clearFlags();
}

///////////////////////////////////////////////////////////////////////////////

sf::RenderWindow const & DrawingHandler::getWindow() const
{
	if (view_.window)
		return *view_.window;
	else
		throw x::error<DrawingHandler>{0, "Window not initialized."};
}

///////////////////////////////////////////////////////////////////////////////

/*Point DrawingHandler::crdBegin() const
{
	return Point{(basic_t)0,(basic_t)window_->getSize().y};
}*/

DrawingHandler::~DrawingHandler()
{

}
