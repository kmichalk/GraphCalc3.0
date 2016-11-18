#include "PredefConstParser.h"

PredefConstParser::PredefConstParser(
	CommandAnalizer const & parentAnalizer)
	:
	ExprParser(parentAnalizer)
{
}

Expr * PredefConstParser::match(x::string const & text) const
{
	return nullptr;
	/*if (value.valid) {
		std::cout << "value: " << value() << std::endl;
		return new Const{value()};
	}*/
}

bool PredefConstParser::basicValidate(x::string const & text) const
{
	return text.size() > 0;
}
