#include "ConstExpr.h"

ConstExpr::ConstExpr(
	CommandAnalizer const & parentAnalizer)
	:
	ExprParser(parentAnalizer)
{
}

Expr * ConstExpr::match(x::string const & text) const
{
	std::cout << "match const: "<<text<<std::endl;
	auto value = text.to<basic_t>();
	if (value.valid) {
		std::cout << "value: " << value.value << std::endl;
		return new Const{value};
	}
}

bool ConstExpr::basicValidate(x::string const & text) const
{
	std::cout << "validate const: " << text << std::endl;
	return
		text.size() > 0 &&
		x::is_digit(text.first());
}
