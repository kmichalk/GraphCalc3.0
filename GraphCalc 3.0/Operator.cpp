#include "Operator.h"


Operator::Operator(
	OperatorExpr const & parentParser, 
	x::string const & sign)
	:
	parentParser{parentParser},
	sign_{sign}
{
}

x::string Operator::getSign() const
{
	return sign_;
}
