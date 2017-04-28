#include "InterfixOperator.h"
#include "Functions.h"
#include "OperatorParser.h"
#include "CommandAnalizer.h"


x::result<size_t> InterfixOperator::findOperator_(x::string const & text) const
{
	int nesting = 0;
	for (auto ch{text.cbegin()}; ch; ++ch) {
		if (*ch == '(') ++nesting;
		if (*ch == ')') --nesting;
		if (*ch == identifier_ && nesting == 0 && ch.pos!=0 && ch.pos!=text.lastpos()) return ch.pos;
	}
	return x::result<size_t>::INVALID;
}

///////////////////////////////////////////////////////////////////////////////

InterfixOperator::InterfixOperator(
	OperatorParser const & parentParser, 
	char identifier)
	:
	Operator(parentParser, identifier)
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * InterfixOperator::match(x::string const & text) const
{
	if (auto opPos = findOperator_(text)) {
		if (Expr* func = Functions::matchFunc(identifier_, 2)) {
			if (!func->set_args({
				parentParser.parentAnalizer.parse(text.substr(0, *opPos - 1)),
				parentParser.parentAnalizer.parse(text.substr(*opPos + 1))}))
				throw x::error<InterfixOperator>{
					x::string{"Illegal number of operands for operator "} +x::string{identifier_}};
			return func;
		}
	}
	return nullptr;
}

size_t InterfixOperator::argnum() const
{
	return 2;
}
