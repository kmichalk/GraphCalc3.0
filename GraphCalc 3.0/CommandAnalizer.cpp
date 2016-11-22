#include "CommandAnalizer.h"
#include "Application.h"
#include "Plot.h"
#include "AnalizerComponent.h"
#include "IllegalCharRule.h"
#include "loops.h"


void CommandAnalizer::removeMarginBrackets_(x::string & line) const
{
	if (line.empty()) return;
	auto brPos = line.match_bracket(0);
	if (brPos && *brPos == line.lastpos())
		line.cut(1, line.lastpos() - 1);
	/*if (line.first() == '(' && line.last() == ')')
		line.cut(1, line.lastpos() - 1);*/
}

bool CommandAnalizer::assertDepth_() const
{
	if (depth_ + 1 > maxDepth_) {
		throw ERROR_MAX_DEPTH_;
	}
}

///////////////////////////////////////////////////////////////////////////////

void CommandAnalizer::analize(x::string line)
{
	depth_ = 0;
	line.remove_if(x::is_whitespace);
	try {
		plotBuffer.clear();
		validator_.process(line);
		process(line);
	}
	catch (x::error<CommandValidator> e) {
		parentApplication.logStream << e << std::endl;
	}	
	/*foreach(component, components_){ 
		component->process(line);
	}*/
}

void CommandAnalizer::addParser(Parser * parser)
{
	parsers_.push_back(parser);
}

///////////////////////////////////////////////////////////////////////////////

void CommandAnalizer::addParser(Parser * parser, size_t priority)
{
	parsers_.insert(parser, priority);
}

///////////////////////////////////////////////////////////////////////////////

//basic_t * CommandAnalizer::currentVar() const
//{
//	return var_;
//}

CommandAnalizer::~CommandAnalizer()
{
	parsers_.erase<x::PTR_DELETE>();
	//delete var_;
}

///////////////////////////////////////////////////////////////////////////////

CommandAnalizer::CommandAnalizer(Application & parentApplication)
	:
	AppComponent	(parentApplication),
	parsers_		{},
	depth_			{0},
	maxDepth_		{DEFAULT_MAX_DEPTH_},
	validator_		{*this}
	//var_{new basic_t{0}}
{
	validator_.addRule(new IllegalCharRule{
		'`', '~', '@', '#', '$', 
		'_', '{', '}', '[', ']', 
		'\"', '\'', '\\', '?', '\n', 
		'\t', '\b', '\r', '\f', '\a', '\0'});
}

void CommandAnalizer::process(x::string line)
{	
	try {
		plotBuffer.push_back({});
		plotBuffer.last()->func = parse(line);;
	}
	catch (x::error<CommandAnalizer> e) {
		parentApplication.logStream << e;
	}
}

Expr * CommandAnalizer::parse(x::string & line) const
{
	assertDepth_();
	++depth_;

	removeMarginBrackets_(line);
	Expr* result = nullptr;
	const_foreach(parser,parsers_){
		if (!*parser) throw ERROR_PARSER_NULLPTR_;
		if (parser->basicValidate(line) && (result = parser->match(line)))
			return result;
	}
	throw x::error<CommandAnalizer>{
		INVALID_EXPRESSION, 
		(x::string{"Invalid expression: "}+line).move()};

	--depth_;
	//return nullptr;
}

///////////////////////////////////////////////////////////////////////////////

const x::error<CommandAnalizer> CommandAnalizer::ERROR_PARSER_NULLPTR_ = {
	CommandAnalizer::PARSER_NULLPTR,
	"Parser was nullptr.\n"
};

const x::error<CommandAnalizer> CommandAnalizer::ERROR_MAX_DEPTH_ = {
	CommandAnalizer::MAX_DEPTH,
	"Max depth of expression reached.\n"
};

const unsigned CommandAnalizer::DEFAULT_MAX_DEPTH_ = 100;

const char CommandAnalizer::DEFAULT_ARG_NAME_ = 'x';

//CommandAnalizer::PlotResult::PlotResult()
//	:
//	expr{nullptr},
//	parameters{Plot::Parameters::DEFAULT}
//{
//}

CommandAnalizer::ParseResult::ParseResult()
	:
	func{nullptr},
	funcName{},
	argName{CommandAnalizer::DEFAULT_ARG_NAME_}
{
}
