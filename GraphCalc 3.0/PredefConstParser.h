#ifndef _PREDEF_CONST_PARSER_H_
#define _PREDEF_CONST_PARSER_H_

#include "Parser.h"


class PredefConstParser:
	public Parser
{
public:
	PredefConstParser(CommandAnalizer const& parentAnalizer);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_PREDEF_CONST_PARSER_H_
