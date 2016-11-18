#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include "xstring.h"
#include "types.h"


class OperatorParser;

class Operator
{
protected:
	char identifier_;

public:
	OperatorParser const& parentParser;

	Operator(
		OperatorParser const& parentParser, 
		char identifier);

	virtual Expr* match(x::string const& text) const abstract;
	virtual size_t argnum() const abstract;
	x::string getSign() const;
};

#endif //_OPERATOR_H_