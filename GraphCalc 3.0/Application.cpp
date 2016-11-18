#include "Application.h"
#include "Functions.h"
#include "Grid.h"
#include "XAxis.h"
#include "OperatorParser.h"
#include "FunctionParser.h"
#include "VariableParser.h"
#include "ConstParser.h"
#include "PostfixOperator.h"
#include "PrefixOperator.h"
#include "InterfixOperator.h"


///////////////////////////////////////////////////////////////////////////////

void Application::initDragHandler_()
{
	auto dragHandler = new DragHandler{*this};

	eventHandler_.add(new KeyPressEvent{
		WKey::LMB,
		true,
		x::FnCall<DragHandler, void(View*)>{ dragHandler, &DragHandler::hook, &view_ }
	});

	eventHandler_.add(new KeyReleaseEvent{
		WKey::LMB,
		true,
		x::Fn<DragHandler, void()>{ dragHandler, &DragHandler::unhook }
	});

	services_.push_back(dragHandler);
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
	commandAnalizer_.addParser(new VariableParser{commandAnalizer_,"x"});
	commandAnalizer_.addParser(new ConstParser{commandAnalizer_});
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
	std::cout << input << std::endl;
	try {
		plotHandler_.createPlot(commandAnalizer_.process(input));
	}
	catch (x::error<PlotHandler> e) {
		std::cout << e.message << std::endl;
	}
	catch (x::error<CommandAnalizer> e) {
		std::cout << e.message<<std::endl;
	}
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
	View::Parameters const& viewParamters)
	:
	//window_			{params, title},
	view_			{*this},
	initViewParams_	{viewParamters},
	plotHandler_	{view_},
	eventHandler_	{DEFAULT_EVENT_PROCESS_PERIOD},
	drawingHandler_	{*this, view_}
	//backgroundColor_{DEFAULT_BACKGROUND_COLOR}
{
}

///////////////////////////////////////////////////////////////////////////////

void Application::process()
{
	while (running_) {
		processServices_();
		//plotHandler_.display();
		//window_.display();
		//window_.clear(backgroundColor_);
		//processWindowEvents_();
	}
	//std::cout << "exit: running " << running_ << ", window_open " << window_.isOpen() << std::endl;
}

///////////////////////////////////////////////////////////////////////////////

void Application::prepare()
{
	parameters.font.loadFromFile("C:/Users/user/consola.ttf");
	add(&eventHandler_);
	add(&drawingHandler_);
	drawingHandler_.addDrawTask(new Grid{view_});
	drawingHandler_.addDrawTask(&plotHandler_);
	initKeyEvents_();
	initDragHandler_();
	initCommandAnalizer_();
	//view_.center();
	//view_.setCalcDensity(0.2);
	

	
}

void Application::initView()
{
	view_.init(initViewParams_);
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
