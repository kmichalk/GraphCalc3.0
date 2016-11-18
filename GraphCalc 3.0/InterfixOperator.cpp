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
		if (*ch == identifier_ && nesting == 0 && ch.pos!=0 && ch.pos!=text.last_pos()) return ch.pos;
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
	auto opPos = findOperator_(text);
	if (opPos.valid) {
		if (auto funcPtr = Functions::twoArgFuncs[x::string{identifier_}.data()]) {
			return new Func<2>{
				funcPtr(),
				parentParser.parentAnalizer.parse(text.substr(0, opPos.value - 1)),
				parentParser.parentAnalizer.parse(text.substr(opPos.value + 1))};
		}
	}
	return nullptr;
}

size_t InterfixOperator::argnum() const
{
	return 2;
}
