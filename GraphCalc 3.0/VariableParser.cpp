#include "VariableParser.h"
#include "CommandAnalizer.h"


VariableParser::VariableParser(
	CommandAnalizer const & parentAnalizer,
	x::string const& varName)
	:
	Parser(parentAnalizer),
	varName_{varName}
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * VariableParser::match(x::string const & text) const
{
	std::cout << "match var: " << text << std::endl;
	return text == varName_ ? new Func<1>{Functions::x} : nullptr;
}

bool VariableParser::basicValidate(x::string const & text) const
{
	std::cout << "validate var: " << text << std::endl;
	return text.size() == varName_.size();
}
