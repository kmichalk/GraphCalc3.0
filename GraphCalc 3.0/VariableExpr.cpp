#include "VariableExpr.h"
#include "CommandAnalizer.h"


VariableExpr::VariableExpr(
	CommandAnalizer const & parentAnalizer,
	x::string const& varName)
	:
	ExprParser(parentAnalizer),
	varName_{varName}
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * VariableExpr::match(x::string const & text) const
{
	std::cout << "match var: " << text << std::endl;
	return text == varName_ ? new Func<1>{Functions::x} : nullptr;
}

bool VariableExpr::basicValidate(x::string const & text) const
{
	std::cout << "validate var: " << text << std::endl;
	return text.size() == varName_.size();
}
