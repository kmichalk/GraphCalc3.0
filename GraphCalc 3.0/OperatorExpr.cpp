#include "OperatorExpr.h"
#include "Functions.h"
#include "CommandAnalizer.h"
#include "loops.h"


OperatorExpr::OperatorExpr(
	CommandAnalizer const & parentAnalizer,
	std::initializer_list<char> operators)
	:
	ExprParser(parentAnalizer),
	operatorPriority_{operators}
{
}

///////////////////////////////////////////////////////////////////////////////

void OperatorExpr::addOperator(char delim)
{
	operatorPriority_.push_back(delim);
}

///////////////////////////////////////////////////////////////////////////////

void OperatorExpr::addOperator(char delim, size_t priority)
{
	operatorPriority_.insert(delim, priority);
}

bool OperatorExpr::basicValidate(x::string const & text) const
{
	std::cout << "validate op: " << text << std::endl;
	return text.size() > 2;
}

///////////////////////////////////////////////////////////////////////////////

Expr * OperatorExpr::match(x::string const & text) const
{
	std::cout << "match op: " << text << std::endl;
	const_foreach(op, operatorPriority_){
		
	}
	return nullptr;
}
