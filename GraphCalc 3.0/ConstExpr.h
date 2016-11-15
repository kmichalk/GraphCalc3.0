#ifndef _CONST_EXPR_H_
#define _CONST_EXPR_H_

#include "ExprParser.h"


class ConstExpr:
	public ExprParser
{
public:
	ConstExpr(CommandAnalizer const& parentAnalizer);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_CONST_EXPR_H_
