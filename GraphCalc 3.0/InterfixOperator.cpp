#include "InterfixOperator.h"
#include "Functions.h"
#include "OperatorExpr.h"
#include "CommandAnalizer.h"


x::result<size_t> InterfixOperator::findOperator_(x::string const & text, char op) const
{
	int nesting = 0;
	for (auto ch{text.cbegin()}; ch; ++ch) {
		if (*ch == '(') ++nesting;
		if (*ch == ')') --nesting;
		if (*ch == op && nesting == 0) return ch.pos;
	}
	return x::result<size_t>::INVALID;
}

InterfixOperator::InterfixOperator(
	OperatorExpr const & parentParser, 
	x::string const & sign)
	:
	Operator(parentParser, sign)
{
}

Expr * InterfixOperator::match(x::string const & text) const
{
	auto opPos = findOperator_(text, sign_[0]);
	if (opPos.valid) {
		x::string delimStr{sign_[0]};
		if (FuncPtr<2> funcPtr = Functions::twoArgFuncs[sign_.data()]) {
			return new Func<2>{funcPtr,
				parentParser.parentAnalizer.parse(text.substr(0, opPos.value - 1)),
				parentParser.parentAnalizer.parse(text.substr(opPos.value + 1))};
		}
	}
	return nullptr;
}

size_t InterfixOperator::argnum() const
{
	return ARGNUM_;
}

