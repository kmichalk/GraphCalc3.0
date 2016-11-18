#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "PlotHandler.h"
#include "DragHandler.h"
#include "DrawingHandler.h"
#include "threaded.h"
#include "keyevent.h"
#include "CommandAnalizer.h"

class Application:
	public MainThread
{
public:
	struct Parameters
	{
		sf::Font font;

		Parameters();
		Parameters(sf::Font const& font);
	};

private:
	static constexpr double DEFAULT_EVENT_PROCESS_PERIOD = 0.025;

	static char const* DEFAULT_TITLE;
	//static sf::Color const DEFAULT_BACKGROUND_COLOR;

	//sf::RenderWindow window_;
	View view_;
	View::Parameters initViewParams_;
	x::vector<ServiceHandler*> services_;
	//DragHandler dragHandler_;
	PlotHandler plotHandler_;
	CommandAnalizer commandAnalizer_;
	EventHandler<x::ExceptionHandling::X_ERRORS> eventHandler_;
	DrawingHandler drawingHandler_;
	sf::Event windowEvent_;

	//void processWindowEvents_();
	void initDragHandler_();
	void initKeyEvents_();
	void initCommandAnalizer_();
	void processServices_();
	void createTestPlots_();

public:
	Parameters parameters;

	Application(
		View::Parameters const& viewParamters = View::Parameters::DEFAULT);

	virtual void process() override;
	virtual void prepare() override;

	void initView();

	virtual ~Application();
};

#endif //_APPLICATION_H_
