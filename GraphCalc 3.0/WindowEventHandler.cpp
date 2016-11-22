#include "WindowEventHandler.h"
#include "View.h"


void WindowEventHandler::readjustView_() const
{
	targetView.window->setView(sf::View{
		(sf::Vector2f)targetView.window->getSize() / 2.0f ,
		(sf::Vector2f)targetView.window->getSize()});
}

WindowEventHandler::WindowEventHandler(View & targetView)
	:
	Service(targetView.parentApplication),
	targetView{targetView}
{
}

void WindowEventHandler::process()
{
	sf::Event windowEvent;

	if (targetView.window->pollEvent(windowEvent)) {
		if (windowEvent.type == sf::Event::EventType::Closed) {
			targetView.window->close();
		}
		if (windowEvent.type == sf::Event::EventType::Resized) {
			targetView.readjust();
		}
	}
}
