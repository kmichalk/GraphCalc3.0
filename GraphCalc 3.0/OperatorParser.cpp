#include "OperatorParser.h"
#include "Functions.h"
#include "CommandAnalizer.h"
#include "Operator.h"
#include "loops.h"


OperatorParser::OperatorParser(CommandAnalizer const & parentAnalizer)
	:
	ExprParser(parentAnalizer)
{
}

OperatorParser::OperatorParser(
	CommandAnalizer const & parentAnalizer,
	std::initializer_list<Operator*> operators)
	:
	ExprParser(parentAnalizer),
	operatorPriority_{operators}
{
}

///////////////////////////////////////////////////////////////////////////////

void OperatorParser::addOperator(Operator * op)
{
	operatorPriority_.push_back(op);
}

///////////////////////////////////////////////////////////////////////////////

void OperatorParser::addOperator(Operator * op, size_t priority)
{
	operatorPriority_.insert(op, priority);
}

///////////////////////////////////////////////////////////////////////////////

bool OperatorParser::basicValidate(x::string const & text) const
{
	std::cout << "validate op: " << text << std::endl;
	return text.size() > 1;
}

///////////////////////////////////////////////////////////////////////////////

Expr * OperatorParser::match(x::string const & text) const
{
	std::cout << "match op: " << text << std::endl;
	const_foreach(op, operatorPriority_){
		if (Expr* result = op->match(text))
			return result;
	}
	return nullptr;
}
