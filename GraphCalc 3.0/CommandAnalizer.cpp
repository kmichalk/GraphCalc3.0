#include "CommandAnalizer.h"
#include "loops.h"


void CommandAnalizer::removeMarginBrackets_(x::string & line) const
{
	if (line.empty()) return;
	if (line.first() == '(' && line.last() == ')')
		line.cut(1, line.last_pos() - 1);
}

CommandAnalizer::CommandAnalizer()
	:
	parsers_{},
	depth_{0},
	maxDepth_{DEFAULT_MAX_DEPTH},
	var_{new basic_t{0}}
{
}

///////////////////////////////////////////////////////////////////////////////

void CommandAnalizer::addParser(ExprParser * parser)
{
	parsers_.push_back(parser);
}

///////////////////////////////////////////////////////////////////////////////

void CommandAnalizer::addParser(ExprParser * parser, size_t priority)
{
	parsers_.insert(parser, priority);
}

///////////////////////////////////////////////////////////////////////////////

basic_t * CommandAnalizer::currentVar() const
{
	return var_;
}

CommandAnalizer::~CommandAnalizer()
{
	parsers_.erase<x::PTR_DELETE>();
	//delete var_;
}

///////////////////////////////////////////////////////////////////////////////

Expr * CommandAnalizer::process(x::string line) const
{
	line.remove_if(x::is_whitespace);
	return parse(line);
}

Expr * CommandAnalizer::parse(x::string & line) const
{
	removeMarginBrackets_(line);
	Expr* result = nullptr;
	const_foreach(parser,parsers_){
		if (!*parser) throw ERROR_PARSER_NULLPTR;
		if (parser->basicValidate(line) && (result = parser->match(line)))
			return result;
	}
	throw x::error<CommandAnalizer>{
		INVALID_EXPRESSION, 
		(x::string{"CommandAnalizer: invalid expression: "}+line).move_data()};
	//return nullptr;
}

///////////////////////////////////////////////////////////////////////////////

const x::error<CommandAnalizer> CommandAnalizer::ERROR_PARSER_NULLPTR = {
	CommandAnalizer::PARSER_NULLPTR,
	"Parser was nullptr.\n"
};