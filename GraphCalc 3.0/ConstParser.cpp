#include "ConstParser.h"

ConstParser::ConstParser(
	CommandAnalizer const & parentAnalizer)
	:
	Parser(parentAnalizer)
{
}

Expr * ConstParser::match(x::string const & text) const
{
	std::cout << "match const: "<<text<<std::endl;
	if (auto value = text.to<basic_t>()) {
		std::cout << "value: " << value << std::endl;
		return new Const{*value};
	}
}

bool ConstParser::basicValidate(x::string const & text) const
{
	std::cout << "validate const: " << text << std::endl;
	return
		text.size() > 0 &&
		x::is_digit(*text.first());
}
