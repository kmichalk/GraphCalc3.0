#include "WindowEventHandler.h"
#include "View.h"


void WindowEventHandler::readjustView_() const
{
	parentView.window->setView(sf::View{
		(sf::Vector2f)parentView.window->getSize() / 2.0f ,
		(sf::Vector2f)parentView.window->getSize()});
}

WindowEventHandler::WindowEventHandler(View & parentView)
	:
	parentView{parentView}
{
}

void WindowEventHandler::process()
{
	sf::Event windowEvent;

	if (parentView.window->pollEvent(windowEvent)) {
		if (windowEvent.type == sf::Event::EventType::Closed) {
			parentView.window->close();
		}
		if (windowEvent.type == sf::Event::EventType::Resized) {
			readjustView_();
		}
	}
}
