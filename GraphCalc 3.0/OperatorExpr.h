#ifndef _CENTER_DELIMITED_EXPR_H_
#define _CENTER_DELIMITED_EXPR_H_

#include "ExprParser.h"
#include "xvector.h"


class OperatorExpr:
	public ExprParser
{
	x::vector<char> operatorPriority_;

public:
	OperatorExpr(
		CommandAnalizer const& parentAnalizer, 
		std::initializer_list<char> operators);

	virtual Expr* match(x::string const& text) const override;
	void addOperator(char delim);
	void addOperator(char delim, size_t priority);
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_CENTER_DELIMITED_EXPR_H_
