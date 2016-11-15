#ifndef DRAWING_HANDLER_H
#define DRAWING_HANDLER_H

#include "threaded.h"
#include "SFML\Graphics.hpp"
#include "DrawTask.h"
#include "View.h"
#include "AppComponent.h"


class Application;

class DrawingHandler:
	public TimedProcess,
	public AppComponent
{
	View& view_;
	x::vector<DrawTask*> drawTasks_;
	sf::Event windowEvent_;

	void processWindowEvents_();
	void readjustView_();

public:
	//double drawPeriod_;
	//x::timer<std::chrono::microseconds> drawTimer_;

	static constexpr double DEFAULT_DRAW_PERIOD = 0.02;
	static constexpr unsigned DEF_WIN_W = 800;
	static constexpr unsigned DEF_WIN_H = 600;
	static constexpr unsigned DEF_FONT_SIZE = 14;
	static constexpr double DEF_SCALE = 100.0;
	static constexpr double DEF_FPS_FRAME_DUR = 0.5;
	static constexpr const char DEF_WIN_NAME[] = "";

	DrawingHandler(
		Application& parent,
		View& view,
		//std::initializer_list<DrawTask*> tasks,
		double drawPeriod = DEFAULT_DRAW_PERIOD);


	void virtual process() override;
	void virtual task() override;
	sf::RenderWindow const& getWindow() const; //TODO: maybe getMousePos method
	//Point crdBegin() const;
	bool setFont(std::string fileName, unsigned fontSize);
	void addDrawTask(DrawTask* task);

	~DrawingHandler();
};


#endif