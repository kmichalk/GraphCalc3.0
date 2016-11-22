#ifndef _CONST_EXPR_H_
#define _CONST_EXPR_H_

#include "Parser.h"


class ConstParser:
	public Parser
{
public:
	ConstParser(CommandAnalizer const& parentAnalizer);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_CONST_EXPR_H_
