#ifndef _COMMAND_ANALIZER_H_
#define _COMMAND_ANALIZER_H_

#include "Parser.h"
#include "AppComponent.h"
#include "CommandValidator.h"
//#include "Plot.h"

class Plot;
class AnalizerComponent;

class CommandAnalizer:
	public AppComponent
{
	static const unsigned DEFAULT_MAX_DEPTH_;
	static const x::error<CommandAnalizer> ERROR_PARSER_NULLPTR_;
	static const x::error<CommandAnalizer> ERROR_MAX_DEPTH_;
	static const char DEFAULT_ARG_NAME_;

	x::vector<Parser*> parsers_;
	x::vector<AnalizerComponent*> components_;
	CommandValidator validator_;
	mutable unsigned depth_;
	unsigned maxDepth_;
	//basic_t* var_;

	void removeMarginBrackets_(x::string& line) const;
	bool assertDepth_() const;

public:
	struct ParseResult
	{
		Expr* func;
		x::string funcName;
		char argName;

		ParseResult();
	};

	enum ErrorNum
	{
		PARSER_NULLPTR, INVALID_EXPRESSION, MAX_DEPTH
	};

	x::vector<ParseResult> plotBuffer;

	CommandAnalizer(Application& parentApplication);

	void process(x::string line);
	Expr* parse(x::string & line) const;
	void analize(x::string line);
	void addParser(Parser* parser);
	void addParser(Parser* parser, size_t priority);
	//basic_t* currentVar() const;

	~CommandAnalizer();
};

#endif //_COMMAND_ANALIZER_H_
