#ifndef _DELIMITED_EXPR_H_
#define _DELIMITED_EXPR_H_

#include "ExprParser.h"


class FunctionExpr:
	public ExprParser
{
	x::string::const_iterator findLeftBracket_(x::string::const_iterator begin) const;
	x::string::const_iterator findRightBracket_(x::string::const_iterator begin) const;
	Expr* makeFunc_() const;

	mutable x::string funcName_;
	mutable x::vector<x::string> argPack_;

public:
	FunctionExpr(CommandAnalizer const& parentAnalizer);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_DELIMITED_EXPR_H_