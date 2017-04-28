#include "ArgumentParser.h"
#include "CommandAnalizer.h"


ArgumentParser::ArgumentParser(
	CommandAnalizer const & parentAnalizer,
	x::string const& varName)
	:
	Parser(parentAnalizer),
	varName_{varName}
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * ArgumentParser::match(x::string const & text) const
{
	std::cout << "match var: " << text << std::endl;
	return text == varName_ ? new Func<1>{Functions::x} : nullptr;
}

bool ArgumentParser::basicValidate(x::string const & text) const
{
	std::cout << "validate var: " << text << std::endl;
	return text.size() == varName_.size();
}
