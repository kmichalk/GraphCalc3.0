#ifndef _COMMAND_ANALIZER_H_
#define _COMMAND_ANALIZER_H_

#include "ExprParser.h"


class CommandAnalizer
{
	static constexpr unsigned DEFAULT_MAX_DEPTH = 10;
	static const x::error<CommandAnalizer> ERROR_PARSER_NULLPTR;

	x::vector<ExprParser*> parsers_;
	unsigned depth_;
	unsigned maxDepth_;
	basic_t* var_;

	void removeMarginBrackets_(x::string& line) const;

public:
	enum ErrorNum
	{
		PARSER_NULLPTR
	};

	CommandAnalizer();

	Expr* process(x::string line) const;
	Expr* parse(x::string const& line) const;
	void addParser(ExprParser* parser);
	void addParser(ExprParser* parser, size_t priority);
	basic_t* currentVar() const;

	~CommandAnalizer();
};

#endif //_COMMAND_ANALIZER_H_
