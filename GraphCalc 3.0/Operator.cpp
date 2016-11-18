#include "Operator.h"


Operator::Operator(
	OperatorParser const & parentParser, 
	char identifier)
	:
	parentParser{parentParser},
	identifier_{identifier}
{
}

///////////////////////////////////////////////////////////////////////////////

x::string Operator::getSign() const
{
	return identifier_;
}
