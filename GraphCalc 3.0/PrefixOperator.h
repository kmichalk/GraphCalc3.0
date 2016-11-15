#ifndef _PREFIX_OPERATOR_H_
#define _PREFIX_OPERATOR_H_

#include "Operator.h"


class PrefixOperator:
	public Operator
{
protected:
	static constexpr size_t ARGNUM_ = 1;

public:
	PrefixOperator(
		OperatorExpr const& parentParser,
		x::string const& sign);

	virtual Expr* match(x::string const& text) const override;
	virtual size_t argnum() const override;
};

#endif //_PREFIX_OPERATOR_H_
