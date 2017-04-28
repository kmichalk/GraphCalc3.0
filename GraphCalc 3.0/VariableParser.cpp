#include "VariableParser.h"
#include "Variables.h"
#include "RefExpr.h"


VariableParser::VariableParser(
	CommandAnalizer const & parentAnalizer)
	:
	Parser(parentAnalizer)
{
}

Expr * VariableParser::match(x::string const & text) const
{
	if (auto identifier = text.first()) {
		if (Variables::validate(*identifier))
			return new Ref{Variables::get(*identifier)};
	}
	return nullptr;
}

bool VariableParser::basicValidate(x::string const & text) const
{
	return text.size() == 1;
}

VariableParser::~VariableParser()
{
}
