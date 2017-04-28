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
	if (*text.last() == identifier_) {
		if (Expr* func = Functions::matchFunc(identifier_, 1)) {
			if (!func->set_args({
				parentParser.parentAnalizer.parse(text.substr(0, text.lastpos() - 1))}))
				throw x::error<PostfixOperator>{
					x::string{"Illegal number of operands for operator "} +x::string{identifier_}};
			return func;
		}
	}
	return nullptr;
}

size_t PostfixOperator::argnum() const
{
	return 1;
}
