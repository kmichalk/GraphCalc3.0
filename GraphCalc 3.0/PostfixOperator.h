#ifndef _POSTFIX_OPERATOR_H_
#define _POSTFIX_OPERATOR_H_

#include "Operator.h"


class PostfixOperator:
	public Operator
{
protected:
	static constexpr size_t ARGNUM_ = 1;

public:
	PostfixOperator(
		OperatorParser const& parentParser,
		char identifier);

	virtual Expr* match(x::string const& text) const override;
	virtual size_t argnum() const override;
};

#endif //_POSTFIX_OPERATOR_H_

