#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include "xstring.h"
#include "types.h"


class OperatorExpr;

class Operator
{
protected:
	x::string sign_;

public:
	OperatorExpr const& parentParser;

	Operator(
		OperatorExpr const& parentParser, 
		x::string const& sign);

	virtual Expr* match(x::string const& text) const abstract;
	virtual size_t argnum() const abstract;
	x::string getSign() const;
};

#endif //_OPERATOR_H_