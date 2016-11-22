#ifndef _XEXPR_H_
#define _XEXPR_H_

#include "Parser.h"


class VariableParser:
	public Parser
{
	static constexpr char const DEFAULT_VAR_NAME[] = "x";

	x::string varName_;

public:
	VariableParser(
		CommandAnalizer const& parentAnalizer, 
		x::string const& varName = DEFAULT_VAR_NAME);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_XEXPR_H_
