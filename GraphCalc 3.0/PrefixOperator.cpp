#include "PrefixOperator.h"
#include "Functions.h"
#include "OperatorParser.h"
#include "CommandAnalizer.h"


PrefixOperator::PrefixOperator(
	OperatorParser const & parentParser, 
	char identifier)
	:
	Operator(parentParser, identifier)
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * PrefixOperator::match(x::string const & text) const
{
	if (*text.first() == identifier_)
		if (auto funcPtr = Functions::oneArgFuncs[x::string{identifier_}.data()])
			return new Func<1>{
				*funcPtr,	
				parentParser.parentAnalizer.parse(text.substr(1))};
	return nullptr;
}

size_t PrefixOperator::argnum() const
{
	return 1;
}
