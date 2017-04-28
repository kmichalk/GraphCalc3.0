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
	if (*text.first() == identifier_) {
		if (Expr* func = Functions::matchFunc(identifier_, 1)) {
			if (!func->set_args({parentParser.parentAnalizer.parse(text.substr(1))}))
				throw x::error<PrefixOperator>{
					x::string{"Illegal number of operands for operator "} + x::string{identifier_}};
			return func;
		}
	}
	return nullptr;
}

size_t PrefixOperator::argnum() const
{
	return 1;
}
