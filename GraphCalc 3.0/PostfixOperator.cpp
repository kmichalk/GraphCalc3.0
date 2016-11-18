#include "PostfixOperator.h"
#include "Functions.h"
#include "OperatorParser.h"
#include "CommandAnalizer.h"


PostfixOperator::PostfixOperator(
	OperatorParser const & parentParser, 
	char identifier)
	:
	Operator(parentParser, identifier)
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * PostfixOperator::match(x::string const & text) const
{
	if (text.last() == identifier_)
		if (auto funcPtr = Functions::oneArgFuncs[x::string{identifier_}.data()])
			return new Func<1>{
			funcPtr(),
			parentParser.parentAnalizer.parse(text.substr(0, text.last_pos() - 1))};
	return nullptr;
}

size_t PostfixOperator::argnum() const
{
	return 1;
}
