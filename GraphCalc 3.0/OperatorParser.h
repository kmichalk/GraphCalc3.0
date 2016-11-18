#ifndef _CENTER_DELIMITED_EXPR_H_
#define _CENTER_DELIMITED_EXPR_H_

#include "ExprParser.h"
#include "xvector.h"


class Operator;

class OperatorParser:
	public ExprParser
{
	x::vector<Operator*> operatorPriority_;

public:
	OperatorParser(
		CommandAnalizer const& parentAnalizer);

	OperatorParser(
		CommandAnalizer const& parentAnalizer, 
		std::initializer_list<Operator*> operators);

	virtual Expr* match(x::string const& text) const override;
	void addOperator(Operator* op);
	void addOperator(Operator* op, size_t priority);
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_CENTER_DELIMITED_EXPR_H_
