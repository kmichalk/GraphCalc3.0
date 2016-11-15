#ifndef _XEXPR_H_
#define _XEXPR_H_

#include "ExprParser.h"


class VariableExpr:
	public ExprParser
{
	static constexpr char const DEFAULT_VAR_NAME[] = "x";

	x::string varName_;

public:
	VariableExpr(
		CommandAnalizer const& parentAnalizer, 
		x::string const& varName = DEFAULT_VAR_NAME);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_XEXPR_H_
