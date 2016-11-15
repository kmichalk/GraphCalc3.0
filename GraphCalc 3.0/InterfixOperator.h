#ifndef _INTERFIX_OPERATOR_H_
#define _INTERFIX_OPERATOR_H_

#include "Operator.h"


class InterfixOperator:
	public Operator
{
protected:
	static constexpr size_t ARGNUM_ = 2;

	x::result<size_t> findOperator_(x::string const & text, char op) const;

public:
	InterfixOperator(
		OperatorExpr const& parentParser,
		x::string const& sign);

	virtual Expr* match(x::string const& text) const override;
	virtual size_t argnum() const override;
};

#endif //_INTERFIX_OPERATOR_H_

