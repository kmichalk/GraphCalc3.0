#include "Application.h"
#include "Functions.h"
#include "Grid.h"
#include "XAxis.h"
#include "OperatorParser.h"
#include "FunctionParser.h"
#include "ArgumentParser.h"
#include "ConstParser.h"
#include "PostfixOperator.h"
#include "PrefixOperator.h"
#include "InterfixOperator.h"
#include "PackParser.h"
#include "VariableParser.h"
#include "WindowEventHandler.h"
#include "DrawTaskHandler.h"
#include "CrossCursor.h"
#include "Variables.h"


///////////////////////////////////////////////////////////////////////////////

void Application::initDragHandler_()
{
	//auto dragHandler = new DragHandler{*this};

	drawingHandler_.addService(new DragHandler{view_,});
	//services_.push_back(dragHandler);
}

///////////////////////////////////////////////////////////////////////////////

void Application::initKeyEvents_()
{
	eventHandler_.add(new KeyPressEvent{
		WKey::C,
		true,
		x::Fn<View, void()>{ &view_, &View::center }
	});

	eventHandler_.add(new KeyCombinationEvent{
		{WKey::LCtrl, WKey::Q},
		true,
		x::Fn<Application, void()>{ this, &Application::stop }
	});

	eventHandler_.add(new KeyPressEvent{
		WKey::LAlt,
		true,
		x::Fn<Application, void()>{ this, &Application::createTestPlots_ }
	});

	eventHandler_.add(new KeyCombinationEvent{
		{WKey::LCtrl, WKey::Del},
		true,
		x::Fn<PlotHandler, void()>{ &plotHandler_, &PlotHandler::clear }
	});
}

void Application::initCommandAnalizer_()
{
	auto opParser = new OperatorParser{commandAnalizer_};
	opParser->addOperator(new InterfixOperator{*opParser, '<'});
	opParser->addOperator(new InterfixOperator{*opParser, '>'});
	opParser->addOperator(new InterfixOperator{*opParser, '='});
	opParser->addOperator(new InterfixOperator{*opParser, '~'});

	opParser->addOperator(new InterfixOperator{*opParser, '+'});
	opParser->addOperator(new InterfixOperator{*opParser, '-'});
	opParser->addOperator(new PrefixOperator{*opParser, '-'});
	opParser->addOperator(new InterfixOperator{*opParser, '*'});
	opParser->addOperator(new InterfixOperator{*opParser, '/'});
	opParser->addOperator(new InterfixOperator{*opParser, '%'});
	opParser->addOperator(new InterfixOperator{*opParser, '^'});
	commandAnalizer_.addParser(opParser);
	commandAnalizer_.addParser(new FunctionParser{commandAnalizer_});
	commandAnalizer_.addParser(new ArgumentParser{commandAnalizer_,"x"});
	commandAnalizer_.addParser(new ConstParser{commandAnalizer_});
	commandAnalizer_.addParser(new VariableParser{commandAnalizer_});
	commandAnalizer_.addParser(new PackParser{commandAnalizer_, '{','}',','});

	Variables::set('A', new Const{1});
}

///////////////////////////////////////////////////////////////////////////////

void Application::processServices_()
{
	foreach(service, services_) service->process();
	//for (auto service{services_.begin()}; service; ++service) {
	//	service->process();
	//}
}

void Application::createTestPlots_()
{
	x::string input;
	std::cout << "f(x) = ";
	std::cin >> input;
	//std::cout << input << std::endl;
	commandAnalizer_.analize(input);
	plotHandler_.createPlot(commandAnalizer_.plotBuffer);
	//try {
	//	plotHandler_.createPlot(commandAnalizer_.process(input));
	//}
	//catch (x::error<PlotHandler> e) {
	//	logStream << e;
	//}
	//catch (x::error<CommandAnalizer> e) {
	//	logStream << e;
	//}
	//plotHandler_.createPlot(new Func<1>{::sin}, {sf::Color{100,200,100}});
	/*plotHandler_.createPlot(Func<2>{Functions::add,
			new Func<1>{::sin, new Func<2>{Functions::mult, new x::math::cval<basic_t>{2.3}, new Func<1>{Functions::x}}},
			new Func<1>{cos},
		},{sf::Color{100,200,100}}
	);
	plotHandler_.createPlot(Func<2>{Functions::add,
			new Func<1>{::sin, new Func<2>{Functions::mult, new x::math::cval<basic_t>{3.7}, new Func<1>{Functions::x}}},
			new Func<1>{cos},
		},{sf::Color{100,100,200}}
	);
	plotHandler_.createPlot(Func<2>{Functions::add,
			new Func<1>{::sin, new Func<2>{Functions::mult, new x::math::cval<basic_t>{4.1}, new Func<1>{Functions::x}}},
			new Func<1>{cos}
		},{sf::Color{200,100,100}}
	);*/
}

///////////////////////////////////////////////////////////////////////////////

Application::Application(
	std::ostream& logStream,
	View::Parameters const& viewParamters)
	:
	//window_			{params, title},
	view_			{*this},
	initViewParams_	{viewParamters},
	plotHandler_	{view_},
	eventHandler_	{DEFAULT_EVENT_PROCESS_PERIOD},
	drawingHandler_	{view_},
	commandAnalizer_{*this},
	logStream		{logStream}
	//backgroundColor_{DEFAULT_BACKGROUND_COLOR}
{
}

///////////////////////////////////////////////////////////////////////////////

void Application::process()
{
	while (running_) {
		Sleep(100);
	}
	//std::cout << "exit: running " << running_ << ", window_open " << window_.isOpen() << std::endl;
}

///////////////////////////////////////////////////////////////////////////////

void Application::prepare()
{
	parameters.font.loadFromFile("C:/Users/user/consola.ttf");

	drawingHandler_.addService(new WindowEventHandler{view_});

	auto drawTaskHandler = new DrawTaskHandler{view_};
	drawTaskHandler->addTask(new Grid{view_});
	drawTaskHandler->addTask(&plotHandler_);
	drawTaskHandler->addTask(new CrossCursor{view_});
	drawingHandler_.addService(drawTaskHandler);
	
	/*drawingHandler_.addDrawTask();
	drawingHandler_.addDrawTask(&plotHandler_);*/
	initKeyEvents_();
	initDragHandler_();
	initCommandAnalizer_();

	add(&eventHandler_);
	add(&drawingHandler_);
	//view_.center();
	//view_.setCalcDensity(0.2);
	

	
}

void Application::initView()
{
	view_.initialize(initViewParams_);
}

void Application::addEvent(Event * event)
{
	eventHandler_.add(event);
}

///////////////////////////////////////////////////////////////////////////////

Application::~Application()
{
	/*if (window_.isOpen())
		window_.close();*/
}

///////////////////////////////////////////////////////////////////////////////

char const* Application::DEFAULT_TITLE = "GraphCalc 3.0";
//sf::Color const Application::DEFAULT_BACKGROUND_COLOR = {20,20,20};

Application::Parameters::Parameters()
{
}

Application::Parameters::Parameters(sf::Font const & font)
	:
	font{font}
{
}
