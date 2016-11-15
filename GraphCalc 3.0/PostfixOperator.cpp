#include "PostfixOperator.h"
#include "Functions.h"
#include "OperatorExpr.h"
#include "CommandAnalizer.h"


PostfixOperator::PostfixOperator(
	OperatorExpr const & parentParser, 
	x::string const & sign)
	:
	Operator(parentParser, sign)
{
}

Expr * PostfixOperator::match(x::string const & text) const
{
	if (text.back(sign_.size()) == sign_)
		if (FuncPtr<1> funcPtr = Functions::oneArgFuncs[sign_.data()])
			return new Func<1>{
			funcPtr,
			parentParser.parentAnalizer.parse(text.substr(sign_.size()))};
	return nullptr;
}

size_t PostfixOperator::argnum() const
{
	return ARGNUM_;
}
